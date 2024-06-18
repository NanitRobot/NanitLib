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
  servoMotor.attach(P1_2);
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

  //pinMode(buzzPin, OUTPUT);

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

bool blok_dnspley_print = false;

void loop() {
  //////////Serial.println("--------");
  if (Serial3.available() > 0) {  // Перевірка наявності даних в порту Serial3

    String input = Serial3.readStringUntil('\n');


if(!blok_dnspley_print){
tft.fillRect(0, 90, 160, 40, ST7735_WHITE);
tft.setCursor(10, 90);
tft.setTextSize(1);
tft.print(String(input));
}
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


/*
    ///Простий спосіб керування
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
    } else if (x <= -127) {
      digitalWrite(MOTOR1_A, LOW);
      analogWrite(MOTOR1_B, z);
      digitalWrite(MOTOR2_A, LOW);
      digitalWrite(MOTOR2_B, LOW);
      Serial.println("LEFT");
    } else if (x >= 127) {
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
    
*/

///Складний спосіб керування
keruvaty_sposib_II();

/*   //// Sonar !!!!
    if (distance(trigPin, echoPin) < 15) {
      tone(buzzPin, 100);
      delay(50);
      tone(buzzPin, 500);
      delay(50);
      noTone(buzzPin);
      digitalWrite(buzzPin, HIGH);
    }
*/
    if (u == 0) servoMotor.write(0);   // Поворот на 0 градусів
    if (u == 1) servoMotor.write(90);  // Поворот на 0 градусів

    // Автоматичне увімкнення фар(світлодіода) при малому освітленні
    bool light = digitalRead(P12_1);

    digitalWrite(red_led, light);
    digitalWrite(grn_led, light);
    // Використання значень x і y
    //////////////////Serial.println("--------");

    /*Serial.print("Received x: ");
    Serial.println(x);
    Serial.print("Received y: ");
    Serial.println(y);
    Serial.print("Received z: ");
    Serial.println(z);
    Serial.print("Received u: ");
    Serial.println(u);*/
  }
}


int distance(byte trggerPin, byte EchoPin) {
  digitalWrite(trggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trggerPin, LOW);

  int cm = pulseIn(EchoPin, HIGH) / 58;
  return cm;
}





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define dipMax 501
#define dipMin 500
bool LRevers = false;
bool RRevers = false;
int ruh = 255;
byte max_gaz = 255;

void keruvaty_sposib_II() {
  max_gaz = z;
  int _Gaz = map(y, 255, -255, 0, 1000);
  int _LivoPravo = map(x, -255, 255, 0, 1000);
  //////////////////////////Спосіб керування №2
  int L_ = 0;
  int R_ = 0;


  Serial.print ("_Gaz= ");  Serial.println (_Gaz);
  Serial.print ("_LivoPravo= ");  Serial.println (_LivoPravo);

  // Якщо газ вперед
  if (_Gaz > dipMax) { 
    blok_dnspley_print = true; /// Блокуємо серіал щоб не заважав

     LRevers = false;
     RRevers = false;

    int ruh = map(_Gaz, 500, 1000, 0, max_gaz);  ///Спільний газ
     Serial.print ("ruh= ");  Serial.println (ruh);

    //Робота з лівим каналом (Розрахунок на те що в ліво буде падати сигнал з 500 до 0)
    if (_LivoPravo <= 500) {
      L_ = 500 - _LivoPravo;
    } else {
      L_ = 0;
    }

   int Rk = 0;
   int Lk = 0;
    L_ = map(L_, 0, 500, 0, ruh);

    
    if (_LivoPravo > 500) {
    Lk = map(_LivoPravo, 500, 1000, ruh, max_gaz);
    } else {Lk = ruh - L_;}
    Serial.print ("L_= ");  Serial.println (L_);
    Serial.print ("Lk= ");  Serial.println (Lk);


    //Робота з правим каналом (Розрахунок на те що в право буде рости сигнал сигнал з 500 до 1000)
    if (_LivoPravo > 500) {
      R_ = _LivoPravo - 500;
    } else {
      R_ = 0;
    }

    R_ = map(R_, 0, 500, 0, ruh);
   
    if (_LivoPravo < 500) {
    Rk = map(_LivoPravo, 500, 0, ruh, max_gaz);
    } else {Rk = ruh - R_;}
    Serial.print ("R_= ");  Serial.println (R_);
    Serial.print ("Rk= ");  Serial.println (Rk);



    /// Тормоз якщо газ на 0
    if (Lk < 1) {
      digitalWrite(MOTOR2_A, LOW);
      digitalWrite(MOTOR2_B, LOW);
    }
    if (Rk < 1) {
      digitalWrite(MOTOR1_A, LOW);
      digitalWrite(MOTOR1_B, LOW);
    }

      digitalWrite(MOTOR1_A, LOW);
      analogWrite(MOTOR1_B, Rk);
      digitalWrite(MOTOR2_A, LOW);
      analogWrite(MOTOR2_B, Lk);
  }



////////////////////////////////////////////////////////////////////////////////////////////////////

  // Якщо газ назад
   if (_Gaz <= dipMax) {

     LRevers = false;
     RRevers = false;

    int ruh = map(_Gaz, 500, 0, 0, max_gaz);  ///Спільний газ
     Serial.print ("ruhNN= ");  Serial.println (ruh);

    //Робота з лівим каналом (Розрахунок на те що в ліво буде падати сигнал з 500 до 0)
    if (_LivoPravo <= 500) {
      L_ = 500 - _LivoPravo;
    } else {
      L_ = 0;
    }

   int Rk = 0;
   int Lk = 0;
    L_ = map(L_, 0, 500, 0, ruh);

    
    if (_LivoPravo < 500) {
    Lk = map(_LivoPravo, 500, 0, ruh, max_gaz);
    } else {Lk = ruh - L_;}
    Serial.print ("L_= ");  Serial.println (L_);
    Serial.print ("Lk= ");  Serial.println (Lk);


    //Робота з правим каналом (Розрахунок на те що в право буде рости сигнал сигнал з 500 до 1000)
    if (_LivoPravo > 500) {
      R_ = _LivoPravo - 500;
    } else {
      R_ = 0;
    }

    R_ = map(R_, 0, 500, 0, ruh);
   
    if (_LivoPravo > 500) {
    Rk = map(_LivoPravo, 500, 1000, ruh, max_gaz);
    } else {Rk = ruh - R_;}
    Serial.print ("R_= ");  Serial.println (R_);
    Serial.print ("Rk= ");  Serial.println (Rk);



    /// Тормоз якщо газ на 0
    if (Lk < 1) {
      digitalWrite(MOTOR2_A, LOW);
      digitalWrite(MOTOR2_B, LOW);
    }
    if (Rk < 1) {
      digitalWrite(MOTOR1_A, LOW);
      digitalWrite(MOTOR1_B, LOW);
    }

      analogWrite(MOTOR1_A, Rk);
      digitalWrite(MOTOR1_B, LOW);
      analogWrite(MOTOR2_A, Lk);
      digitalWrite(MOTOR2_B, LOW);
  }
}




