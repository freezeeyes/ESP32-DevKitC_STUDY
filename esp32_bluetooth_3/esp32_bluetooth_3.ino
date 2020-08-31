#include <BluetoothSerial.h>

#define HIGH (1)
#define LOW (0)
#define LED_PIN 22

BluetoothSerial SerialBT;
int flag = LOW;

void setup()
{
  //  Bluetoothシリアルに名前を指定する
  SerialBT.begin("ESP32");
  //  シリアル通信の通信速度を指定する
  Serial.begin(115200);
  //  LED用のピンを出力モードに指定する
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  //  Bluetoothで受信できるバイト数を取得する
  if(SerialBT.available())
  {
    //  データを受信する
    char ch = SerialBT.read();
    //  文字列を送信する
    Serial.print(ch);
    //  受信データによってLEDの点灯消灯を切り替える
    switch(ch)
    {
      case '0':
        flag = LOW;
        break;
      case '1':
        flag = HIGH;
        break;
    }
    digitalWrite(LED_PIN, flag);
  }
}
