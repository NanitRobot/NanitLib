#ifndef ESP_RGB_BUILDIN
#define ESP_RGB_BUILDIN

#define BLUE_ON()                                                              \
  pinMode(13, OUTPUT);                                                         \
  digitalWrite(13, HIGH)
#define BLUE_OFF()                                                             \
  delay(25);                                                                   \
  pinMode(13, INPUT);                                                          \
  digitalWrite(13, LOW)

#define RED_ON()                                                               \
  pinMode(15, OUTPUT);                                                         \
  digitalWrite(15, HIGH)
#define RED_OFF()                                                              \
  pinMode(15, INPUT);                                                          \
  digitalWrite(15, LOW)
#endif