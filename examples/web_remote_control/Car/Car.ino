#include <NanitLib.h>
#include <Servo.h>

Servo servoMotor;  // Створюємо об'єкт сервопривода
int x, y, z, u;
byte buzzPin = P12_2;
byte trigPin = P6_1;
byte echoPin = P6_4;

byte red_led = P4_2;
byte grn_led = P4_3;


void setup() {
  servoMotor.attach(P11_4);
  Nanit_Base_Start();
  Serial.begin(57600);   // Ініціалізація порту Serial (для виводу дебаг-інформації)
  Serial3.begin(57600);  // Ініціалізація порту Serial3 (порт UART)

  pinMode(MOTOR_ENABLE, OUTPUT);
  digitalWrite(MOTOR_ENABLE, HIGH);
  pinMode(P12_2, OUTPUT);
  digitalWrite(P12_2, HIGH);
  pinMode(P1_3, OUTPUT);
  pinMode(P1_4, OUTPUT);
  pinMode(P12_3, OUTPUT);
  pinMode(P12_4, OUTPUT);

  pinMode(buzzPin, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(red_led, OUTPUT);
  pinMode(grn_led, OUTPUT);

  digitalWrite(P1_3, LOW);
  digitalWrite(P1_4, LOW);
  digitalWrite(P12_3, LOW);
  digitalWrite(P12_4, LOW);
  noTone(buzzPin);
  digitalWrite(buzzPin, HIGH);
  digitalWrite(trigPin, LOW);
}

void loop() {
  Serial.println("--------");
  if (Serial3.available() > 0) {  // Перевірка наявності даних в порту Serial3

    String input = Serial3.readStringUntil('\n');


    {
      // Використовуємо strtok для розділення рядка на числа
      char *str = strdup(input.c_str());
      char *token = strtok(str, ",");
      enum {  ///< Перелік аргументів які отримуємо
        ARG_X = 0,  ///<
        ARG_Y,      ///<
        ARG_Z,      ///<
        ARG_U,      ///<
        ARG_COUNT  ///< Для створення масиву це кількість аргументів що
                   ///< отримуємо
      };
      byte index{ARG_X};  ///< Лічильник елемнтів
      int args[ARG_COUNT];  ///< Масив для зберігання елементів
      /** Повторюватимемо дії поки */
      while (token                   /* поки є рядок*/
             && (index < ARG_COUNT)) /*та місце у масиві */
      {
        args[index++] = atoi(token); /** < шукаємо числа у рядку, якщо знаходимо
                              записуємо у першу комірку і одразу перводимо
                              вказівник на наступну комірку */
        token = strtok(NULL, ","); /** < шукаємо цифри у до наступної коми */
      }
      x = args[ARG_X];
      y = args[ARG_Y];
      z = args[ARG_Z];
      u = args[ARG_U];
      free(str);
    }


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


#if 0
    if(abs(x)>dedZone){
    analogWrite(MOTOR1_A, (x>0)?x:0);
    analogWrite(MOTOR1_B, (x<0?(-x):0));

    analogWrite(MOTOR2_B, (x>0)?x:0);
    analogWrite(MOTOR2_A, (x<0?(-x):0));
    }

    if(abs(y)>dedZone){
    analogWrite(MOTOR1_A, (y>0)?y:0);
    analogWrite(MOTOR1_B, (y<0?(-y):0));

    analogWrite(MOTOR2_A, (y>0)?y:0);
    analogWrite(MOTOR2_B, (y<0?(-y):0));
    }



    if((abs(x)<dedZone)and (abs(y)<dedZone)){
    analogWrite(MOTOR1_A, 0);
    analogWrite(MOTOR1_B, 0);

    analogWrite(MOTOR2_B, 0);
    analogWrite(MOTOR2_A, 0);
    }

#endif
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
      digitalWrite(MOTOR1_A, LOW);
      analogWrite(MOTOR1_B, z);
      digitalWrite(MOTOR2_A, LOW);
      digitalWrite(MOTOR2_B, LOW);
      Serial.println("LEFT");
    } else if (x <= -127) {
      digitalWrite(MOTOR1_A, LOW);
      digitalWrite(MOTOR1_B, LOW);
      digitalWrite(MOTOR2_A, LOW);
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

    // Автоматичне увімкнення фар(світлодіода) при малому освітленні
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