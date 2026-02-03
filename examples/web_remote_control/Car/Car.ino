#include <NanitLib.h>
#include <Servo.h>
#include <stdlib.h>   // strdup, free, atoi
#include <string.h>   // strtok

////////////////////////////////////////////////////////////////////////////////////////////////////
// Hardware
////////////////////////////////////////////////////////////////////////////////////////////////////
Servo servoMotor;

int x, y, z, u;

byte buzzPin = P12_2;
byte trigPin = P6_1;
byte echoPin = P6_4;

byte red_led = P4_2;
byte grn_led = P4_3;

////////////////////////////////////////////////////////////////////////////////////////////////////
// Global state
////////////////////////////////////////////////////////////////////////////////////////////////////
bool blok_dnspley_print = false;
byte max_gaz = 255;

////////////////////////////////////////////////////////////////////////////////////////////////////
// Drive output structure  ✅ MUST BE BEFORE ANY FUNCTION THAT USES IT
////////////////////////////////////////////////////////////////////////////////////////////////////
struct DriveOut {
  uint8_t pwmL;
  uint8_t pwmR;
  bool dirL;     // false = forward, true = reverse
  bool dirR;     // false = forward, true = reverse
  bool brakeL;   // true = brake (both pins LOW)
  bool brakeR;   // true = brake (both pins LOW)
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Utility helpers
////////////////////////////////////////////////////////////////////////////////////////////////////
static inline int clampInt(int v, int lo, int hi) {
  if (v < lo) return lo;
  if (v > hi) return hi;
  return v;
}

static inline int absInt(int v) {
  return (v < 0) ? -v : v;
}

// Convert -255..255 to -100..100 percent
static inline int toPercentSigned(int v255) {
  v255 = clampInt(v255, -255, 255);
  return (v255 * 100) / 255;
}

// Convert 0..100 percent to PWM 0..maxPWM
static inline uint8_t percentToPwm(int pct, uint8_t maxPWM) {
  pct = clampInt(pct, 0, 100);
  return (uint8_t)((pct * (int)maxPWM) / 100);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Percent-based differential drive mixing
////////////////////////////////////////////////////////////////////////////////////////////////////
DriveOut Generate_PWM_values(int xRaw, int yRaw, uint8_t maxPWM, int backlashPct = 8) {
  DriveOut out{};

  int throttlePct = toPercentSigned(yRaw);   // -100..100
  int steerPct    = toPercentSigned(xRaw);   // -100..100

  // Deadzone
  if (absInt(throttlePct) < backlashPct) throttlePct = 0;
  if (absInt(steerPct)    < backlashPct) steerPct    = 0;

  // Default = stop/brake
  out.pwmL = 0;
  out.pwmR = 0;
  out.dirL = false;
  out.dirR = false;
  out.brakeL = true;
  out.brakeR = true;

  // Full stop
  if (throttlePct == 0 && steerPct == 0) {
    return out;
  }

  // Driving mode (forward/back)
  if (throttlePct != 0) {
    bool reverse = (throttlePct < 0);
    int base = absInt(throttlePct);   // 0..100

    // Tank mixing:
    // steerPct > 0 => right turn => left stronger, right weaker
    int leftPct  = clampInt(base + steerPct, 0, 100);
    int rightPct = clampInt(base - steerPct, 0, 100);

    out.dirL = reverse;
    out.dirR = reverse;

    out.pwmL = percentToPwm(leftPct,  maxPWM);
    out.pwmR = percentToPwm(rightPct, maxPWM);

    out.brakeL = (out.pwmL < 1);
    out.brakeR = (out.pwmR < 1);

    return out;
  }

  // Spin-in-place mode (throttle == 0, steer != 0)
  {
    int spin = absInt(steerPct);     // 0..100
    bool spinRight = (steerPct > 0);

    // Spin right: left forward, right reverse
    // Spin left : left reverse, right forward
    out.dirL = !spinRight;
    out.dirR = spinRight;

    out.pwmL = percentToPwm(spin, maxPWM);
    out.pwmR = percentToPwm(spin, maxPWM);

    out.brakeL = (out.pwmL < 1);
    out.brakeR = (out.pwmR < 1);

    return out;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Apply drive signals to motors
////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplyDrive(const DriveOut& d) {

  // LEFT MOTOR = MOTOR2
  if (d.brakeL) {
    digitalWrite(MOTOR2_A, LOW);
    digitalWrite(MOTOR2_B, LOW);
  } else {
    if (!d.dirL) { // forward
      digitalWrite(MOTOR2_A, LOW);
      analogWrite(MOTOR2_B, d.pwmL);
    } else {       // reverse
      analogWrite(MOTOR2_A, d.pwmL);
      digitalWrite(MOTOR2_B, LOW);
    }
  }

  // RIGHT MOTOR = MOTOR1
  if (d.brakeR) {
    digitalWrite(MOTOR1_A, LOW);
    digitalWrite(MOTOR1_B, LOW);
  } else {
    if (!d.dirR) { // forward
      digitalWrite(MOTOR1_A, LOW);
      analogWrite(MOTOR1_B, d.pwmR);
    } else {       // reverse
      analogWrite(MOTOR1_A, d.pwmR);
      digitalWrite(MOTOR1_B, LOW);
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Replacement for old keruvaty()
////////////////////////////////////////////////////////////////////////////////////////////////////
void keruvaty() {
  max_gaz = (byte)z;

  DriveOut d = Generate_PWM_values(x, y, max_gaz, 8);
  ApplyDrive(d);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Distance sensor
////////////////////////////////////////////////////////////////////////////////////////////////////
int distance(byte triggerPin, byte echoPin) {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  int cm = pulseIn(echoPin, HIGH) / 58;
  return cm;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// SETUP
////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {

  servoMotor.attach(P1_2);

  Nanit_Base_Start();
  Serial.begin(57600);
  Serial3.begin(57600);

  pinMode(MOTOR_ENABLE, OUTPUT);
  digitalWrite(MOTOR_ENABLE, HIGH);

  pinMode(buzzPin, OUTPUT);
  digitalWrite(buzzPin, HIGH);

  pinMode(P1_3, OUTPUT);
  pinMode(P1_4, OUTPUT);
  pinMode(P12_3, OUTPUT);
  pinMode(P12_4, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(red_led, OUTPUT);
  pinMode(grn_led, OUTPUT);

  digitalWrite(P1_3, LOW);
  digitalWrite(P1_4, LOW);
  digitalWrite(P12_3, LOW);
  digitalWrite(P12_4, LOW);

  noTone(buzzPin);
  digitalWrite(trigPin, LOW);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// LOOP
////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {

  if (Serial3.available() > 0) {

    String input = Serial3.readStringUntil('\n');

    if (!blok_dnspley_print) {
      tft.fillRect(0, 90, 160, 40, ST7735_WHITE);
      tft.setCursor(10, 90);
      tft.setTextSize(1);
      tft.print(input);
    }

    // Parse CSV: x,y,z,u
    char *str = strdup(input.c_str());
    char *token = strtok(str, ",");

    int args[4] = {0, 0, 0, 0};
    byte index = 0;

    while (token && index < 4) {
      args[index++] = atoi(token);
      token = strtok(NULL, ",");
    }

    free(str);

    x = args[0];
    y = args[1];
    z = args[2];
    u = args[3];

    // Deadzone on raw values (optional, you had this before)
    const int dedZone = 35;
    if (abs(x) < dedZone) x = 0;
    if (abs(y) < dedZone) y = 0;

    // Sanity limits
    if (x > 255 || x < -255) return;
    if (y > 255 || y < -255) return;
    if (z > 255 || z < 0)    return;
    if (u > 1   || u < 0)    return;

    // Drive
    keruvaty();

    // Servo control
    if (u == 0) servoMotor.write(0);
    if (u == 1) servoMotor.write(90);

    // Automatic lights
    bool light = digitalRead(P12_1);
    digitalWrite(red_led, light);
    digitalWrite(grn_led, light);
  }
}
