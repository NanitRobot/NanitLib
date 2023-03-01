#ifndef NANITPINOUT_H_
#define NANITPINOUT_H_



extern uint8_t MOTOR1_A;
extern uint8_t MOTOR1_B;
extern uint8_t P1_6; 
extern uint8_t P1_4;
extern uint8_t P1_3;
extern uint8_t P8_3;
extern uint8_t P10_3;
extern uint8_t P10_2;
extern uint8_t P7_6;
extern uint8_t P7_4;
extern uint8_t P9_6; 
extern uint8_t P9_4;


#define MOTOR_ENABLE 40 //запустить драйвер на мотор

#define MOTOR2_A 11
#define MOTOR2_B 12

#define BUTTON 3 

///Порт 1
#define P1_2 A6 
#define P1_1 A7 

///Порт 2
#define P2_6 A8  
#define P2_4 A8
#define P2_3 42 
#define P2_2 A9
#define P2_1 A10

///Порт 3
#define P3_6 31 /// Стара версія
#define P3_4 31
#define P3_3 30
#define P3_2 25

///Порт 4
#define P4_6 46 // ШІМ, червоний світлодіод (стара версія)
#define P4_4 46 // ШІМ, червоний світлодіод
#define P4_3 45 // ШІМ, синій світлодіод
#define P4_2 44 // ШІМ, зелений світлодіод
#define P4_1 A11

///Порт 5
#define P5_6 33 /// Стара версія
#define P5_4 33 
#define P5_3 A12
#define P5_2 A1
#define P5_1 2 // INT.0 pin

///Порт 6
#define P6_6 22 /// Стара версія
#define P6_4 22
#define P6_3 A13
#define P6_2 A14
#define P6_1 23

///Порт 7
#define P7_3 28
#define P7_2 A4
#define P7_1 A3

///Порт 8


///Порт 9
#define P9_3 19  /// INT.2 pin
#define P9_2 20 //SDA
#define P9_1 21 //SCL

///Порт 10
#define P10_6 6  /// Стара версія
#define P10_4 6
#define P10_1 A2

///Порт 11
#define P11_6 32   /// Стара версія
#define P11_4 32
#define P11_3 43

///Порт 12
#define P12_6 11/// Мотор М2_А /// Стара версія
#define P12_4 11
#define P12_3 12/// Мотор М2_В
#define P12_2 34
#define P12_1 36

//порти дисплею

#define TFT_CS 48 
#define TFT_RES 37
#define TFT_DC 49
#define TFT_BL 4
#define TFT_SCK 52
#define TFT_MOSI 51




#endif
