# Як працювати з бібліотекою

Для початку роботи з бібліотекою достатньо підключити файл заголовків `NanitLib.h`.
Цього достанньо для початку роботи з платами `Nanit`

Найпростіший код яки можна помигати підсідкою дисплею

```cpp
#include <NanitLib.h>
void setup(){
    pinMode(TFT_BL,OUTPUT);///< До цього піна підключена підсвідка дисплею
                           ///< тому ми можемо лише писати цей пін.
                           ///< Читати цей пін безглуздо
}
const short OneSec{1000};
void loop(){
    digitalWrite(TFT_BL,HIGH);
    delay(OneSec);
    digitalWrite(TFT_BL,LOW);
    delay(OneSec);
}
```