#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup()
{
  //  Bluetoothシリアルに名前を指定する
  SerialBT.begin("ESP32");
  //  シリアル通信の通信速度を指定する
  Serial.begin(115200);
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
  }
}
