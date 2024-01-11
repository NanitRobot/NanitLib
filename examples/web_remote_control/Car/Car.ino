#include <NanitLib.h>
#include <Servo.h>

Servo servoMotor;  // Створюємо об'єкт сервопривода
int x, y, z, u;
byte buzzPin = P12_2;
byte trigPin = P6_1;
byte echoPin = P6_4;

int red_led = P4_2;
int grn_led = P4_3;


void setup() {
  servoMotor.attach(P11_4);
  Nanit_Base_Start();
  Serial.begin(9600);   // Ініціалізація порту Serial (для виводу дебаг-інформації)
  Serial3.begin(9600);  // Ініціалізація порту Serial3 (порт UART)

  pinMode(40, OUTPUT);
  digitalWrite(40, 1);
  pinMode(P12_2, OUTPUT);
  digitalWrite(P12_2, 1);
  pinMode(P1_3, OUTPUT);
  pinMode(P1_4, OUTPUT);
  pinMode(P12_3, OUTPUT);
  pinMode(P12_4, OUTPUT);

  pinMode(buzzPin, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(red_led, OUTPUT);
  pinMode(grn_led, OUTPUT);

  digitalWrite(P1_3, 0);
  digitalWrite(P1_4, 0);
  digitalWrite(P12_3, 0);
  digitalWrite(P12_4, 0);
  noTone(buzzPin);
  digitalWrite(buzzPin, HIGH);
  digitalWrite(trigPin, LOW);
}

void loop() {
  Serial.println("--------");
  if (Serial3.available() > 0) {  // Перевірка наявності даних в порту Serial3

    String input = Serial3.readStringUntil('\n');

    // Використовуємо strtok для розділення рядка на числа
    char *str = strdup(input.c_str());
    char *token = strtok(str, ",");
    if (token) {
      x = atoi(token);
      token = strtok(NULL, ",");
      if (token) {
        y = atoi(token);
        token = strtok(NULL, ",");
        if (token) {
          z = atoi(token);
          token = strtok(NULL, ",");
          if (token) {
            u = atoi(token);
          }
        }
      }
    }
    free(str);

    const int dedZone = 35;
    if (abs(x) < dedZone) x = 0;
    if (abs(y) < dedZone) y = 0;

    if (x > 255) return;
    if (x < -255) return;

    if (y > 255) return;
    if (y < -255) return;

    if (z > 255) return;
    if (z < 149) return;

    if (u > 1) return;
    if (u < 0) return;


    if (y >= 127) {
      analogWrite(MOTOR1_A, z);
      digitalWrite(MOTOR1_B, LOW);
      analogWrite(MOTOR2_A, z);
      digitalWrite(MOTOR2_B, LOW);
      Serial.println("DOWN");
    } else if (y <= -127) {
      digitalWrite(MOTOR1_A, LOW);
      analogWrite(MOTOR1_B, z);
      digitalWrite(MOTOR2_A, LOW);
      analogWrite(MOTOR2_B, z);
      Serial.println("UP");
    } else if (x >= 127) {
      digitalWrite(MOTOR1_A, 0);
      analogWrite(MOTOR1_B, z);
      digitalWrite(MOTOR2_A, LOW);
      digitalWrite(MOTOR2_B, LOW);
      Serial.println("LEFT");
    } else if (x <= -127) {
      digitalWrite(MOTOR1_A, LOW);
      digitalWrite(MOTOR1_B, LOW);
      digitalWrite(MOTOR2_A, 0);
      analogWrite(MOTOR2_B, z);
      Serial.println("RIGHT");
    } else if (abs(x) < 30 && abs(y) < 30) {
      digitalWrite(MOTOR1_A, LOW);
      digitalWrite(MOTOR1_B, LOW);
      digitalWrite(MOTOR2_A, LOW);
      digitalWrite(MOTOR2_B, LOW);
      Serial.println("STOP");
    }

    if (distance(trigPin, echoPin) < 15) {
      tone(buzzPin, 100);
      delay(50);
      tone(buzzPin, 500);
      delay(50);
      noTone(buzzPin);
      digitalWrite(buzzPin, HIGH);
    }

    if (u == 0) servoMotor.write(0);   // Поворот на 0 градусів
    if (u == 1) servoMotor.write(90);  // Поворот на 0 градусів


    bool light = digitalRead(P12_1);

    digitalWrite(red_led, light);
    digitalWrite(grn_led, light);
    // Використання значень x і y
    Serial.println("--------");

    Serial.print("Received x: ");
    Serial.println(x);
    Serial.print("Received y: ");
    Serial.println(y);
    Serial.print("Received z: ");
    Serial.println(z);
    Serial.print("Received u: ");
    Serial.println(z);
  }
}


int distance(byte trggerPin, byte EchoPin) {
  digitalWrite(trggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trggerPin, LOW);

  int cm = pulseIn(EchoPin, HIGH) / 58;
  return cm;
}