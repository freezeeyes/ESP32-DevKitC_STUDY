#define HIGH (1)
#define LOW (0)

#define LED_PIN 22

void setup()
{
  //  LED用のピンを出力モードに指定する
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  //  LEDを１秒間点灯させる
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  //  LEDを１秒間消灯させる
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
