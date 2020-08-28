#define HIGH (1)
#define LOW (0)

#define LED_PIN 22

int flag = HIGH;

void setup()
{
  //  シリアル通信の通信速度を指定する
  Serial.begin(115200);
  //  LED用のピンを出力モードに指定する
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  //  LEDの出力値を切り替える
  flag = flag ? LOW : HIGH;
  //  LED状態を送信する
  Serial.println(flag ? "LED ON" : "LED OFF");
  //  LEDの点灯消灯を制御する
  digitalWrite(LED_PIN, flag);
  //  マイクロ秒指定で１秒間待機する
  delayMicroseconds(1000000);
}
