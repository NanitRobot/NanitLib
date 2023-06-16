# Як працювати з бібліотекою

Для початку роботи з бібліотекою достатньо підключити файл заголовків `NanitLib.h`.
Цього достанньо для початку роботи з платами `Nanit`

Найпростіший код яким можна помигати підсвідкою дисплею

```cpp
#include <NanitLib.h>
void setup(){
    pinMode(TFT_BL,OUTPUT);///< До цього піна підключена підсвідка дисплею
                           ///< тому ми можемо лише писати цей пін.
                           ///< Читати цей пін безглуздо
}
const short OneSec{1000};
void loop(){
    digitalWrite(TFT_BL,HIGH);///< Вмикаємо
    delay(OneSec);
    digitalWrite(TFT_BL,LOW); ///< Вимикаємо
    delay(OneSec);
}
```

Попередній приклад демонстрував просте вмикання та вимикання дисплею

Керувати підсідкою можна також через зміну яскравості


```cpp
#include <NanitLib.h>
void setup() {
  pinMode(TFT_BL, OUTPUT);  ///< До цього піна підключена підсвідка дисплею
                            ///< тому ми можемо лише писати цей пін.
                            ///< Читати цей пін безглуздо
}
const short _delay{3};
void loop() {
  for (short rizing{0}; rizing < 255; rizing += 1) {
    analogWrite(TFT_BL, rizing); ///< Поступово засвічуємо
    delay(_delay);
  }
  for (short folding{255}; folding > 0; folding -= 1) {
    analogWrite(TFT_BL, folding); ///< Поступово гасимо
    delay(_delay);
  }
}
```