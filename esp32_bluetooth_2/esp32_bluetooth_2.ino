#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup()
{
  //  Bluetoothシリアルに名前を指定する
  SerialBT.begin("ESP32");
}

void loop()
{
  //  文字列を送信する
  SerialBT.print("Hello ");
  //  改行付きの文字列を送信する
  SerialBT.println("World!!");
  //  １秒間待機する
  delay(1000);
}
