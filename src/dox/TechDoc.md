# Характеристики
# Технічні можливості


Nanit (далі по тексту -- пристрій) призначений для вивчення основ проектування та програмування автоматизованих чи роботизованих автоматичних систем на основі мікроконтролерів
 
 Технічні дані 
 |Параметр                            | Значення | 
 |:-----------------------------------|:--------:|
 |Напруга живлення                    |    5В    |
 |Напруга живлення вбудованої батареї |3,7 — 4,2В|
 |Ємність вбудованого акумулятора     | 1800mA-h |
 |Захист батареї від КЗ та перерозряду|    +     |
 |Максимальний струм навантаження на<BR/> вбудований драйвер двигуна|1A|
 |Піковий струм навантаження на вбудований драйвер двигуна|2A|
 |Максимальне навантаження на сигнальний пін|20мА|
 |Вихідний сигнал HIGH                |   5В     |
 |Толерантність то 3.3вольт логіки    |    +     |
 |Тактова частота мікроконтролера     |  16МГц   |
 |Об’єм пам’яті програми              |  256KB   |
 |Об’єм енергонезалежної пам’яті      |   4KB    |
 |Об’єм оперативної пам’яті           |   8KB    |
 |Апаратні інтерфейси                 |2xUART, IIC, USB|
 |ШІМ виводів                         |   12     |
 |Цифрові входи/виходи загального призначення|47 |
 |Можуть працювати в режимі АЦП входи |   14     |
 |Можуть працювати в режимі ШІМ       |   12     |
 |Розрядність АЦП                     | 10bit    |
 |Зовнішнє переривання                |   3      |
 |Роздільна здатність дисплею         |160х128   |
 |Кількість кольорів дисплею          | 65535    |
 |Кількість фізичних  портів          |   12     |


 |Nanitdef              |Analog |    PIN       | Напрямок роботи піна|
 |:--------------------:|:-----:|:------------:|:-------------------:|
 |      @ref P1_1       |  A7   |   61(IO)     |          IO         |
 |      @ref P1_2       |  A6   |   60(IO)     |          IO         |
 |      @ref P1_3       |    @ref DiffPin      ||         O          |
 |      @ref P1_4       |    @ref DiffPin      ||         O          |
 |      @ref P2_1       |  A10  |   64(IO)     |          IO         |
 |      @ref P2_2       |  A9   |   63(IO)     |          IO         |
 |      @ref P2_3       |       |   42(IO)     |          IO         |
 |      @ref P2_4       |  A8   |   62(IO)     |          IO         |
 |      @ref P3_1       |     @ref MEGACORE    ||          IO        |
 |      @ref P3_2       |       |    25(IO)    |          IO         |
 |      @ref P3_3       |       |    30(IO)    |          IO         |
 |      @ref P3_4       |       |    31(IO)    |          IO         |
 |      @ref P4_1       |  A11  |    65(IO)    |          IO         |
 |      @ref P4_2       |       |    44(IO)    |          IO         |
 |      @ref P4_3       |       |    45(IO)    |          IO         |
 |      @ref P4_4       |       |    46(IO)    |          IO         |
 |      @ref P5_1       |       |    2(IO)     |          IO         |
 |      @ref P5_2       |  A1   |    54(IO)    |          IO         |
 |      @ref P5_3       |  A12  |    66(IO)    |          IO         |
 |      @ref P5_4       |       |    33(IO)    |          IO         |
 |      @ref P6_1       |       |    23(IO)    |          IO         |
 |      @ref P6_2       |  A14  |    67(IO)    |          IO         |
 |      @ref P6_3       |  A13  |    67(IO)    |          IO         |
 |      @ref P6_4       |       |    22(IO)    |          IO         |
 |      @ref P7_1       |   A3  |    57(IO)    |          IO         |
 |      @ref P7_2       |   A4  |    58(IO)    |          IO         |
 |      @ref P7_3       |       |    25(IO)    |          IO         |
 |      @ref P7_4       |    @ref DiffPin      ||         IO         |
 |      @ref P8_1       |       |      1       |          IO         |
 |      @ref P8_2       |       |      0       |          IO         |
 |      @ref P8_3       |       |      5       |          IO         |
 |      @ref P8_4       |                 RESET                     |||
 |      @ref P9_1       |       |    21(IO)    |          IO         |
 |      @ref P9_2       |       |    20(IO)    |          IO         |
 |      @ref P9_3       |       |    19(IO)    |          IO         |
 |      @ref P9_4       |    @ref DiffPin      ||         IO         |
 |     @ref P10_1       |   A2  |    56(IO)    |          IO         |
 |     @ref P10_2       |    @ref DiffPin      ||         IO         |
 |     @ref P10_3       |    @ref DiffPin      ||         IO         |
 |     @ref P10_4       |       |    6(IO)     |          IO         |
 |     @ref P11_1       |       |              |          O          |
 |     @ref P11_2       |       |              |          O          |
 |     @ref P11_3       |       |    43(IO)    |          IO         |
 |     @ref P11_4       |       |    32(IO)    |          IO         |
 |     @ref P12_1       |       |    36(IO)    |          IO         |
 |     @ref P12_2       |       |    34(IO)    |          IO         |
 |     @ref P12_3       |       |     12(O)    |          O          |
 |     @ref P12_4       |       |     11(O)    |          O          |
 |   @ref BATTERY_PIN   |  A15  |      --      |          I          |
 |  @ref MOTOR_ENABLE   |       |     40(0)    |          O          |
 |   @ref MOTOR_FAIL    |       |     41(I)    |          I          |
 |@ref BUILDIN_STRIP_LED|       |     27(0)    |          O          |