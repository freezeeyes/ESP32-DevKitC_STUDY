/*************************************************************
 * TITLE: タイマー割り込みとBluetoothのプログラム１
 * DESCRIPTION:
 *     割り込み処理で受信したBluetoothデータに応じてLEDを点灯させる
 *************************************************************/


#include <BluetoothSerial.h>
#include <uTimerLib.h>

#define HIGH (1)
#define LOW (0)
#define LED_PIN1 22
#define LED_PIN2 21
#define WAIT_TIME 250

BluetoothSerial SerialBT;
char cmd = '0';

void cmt_bluetooth(void);
void display_led1(void);
void display_led2(void);
void display_led3(void);

void setup()
{
  //  Bluetoothシリアルに名前を指定する
  SerialBT.begin("ESP32");
  //  LED用のピンを出力モードに指定する
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  //  １秒間隔のタイマー割り込みを開始する
  TimerLib.setInterval_s(cmt_bluetooth, 1);
}

void loop()
{
  //  受信データによってLEDの点灯消灯を切り替える
  switch(cmd)
  {
    case '0':
      display_led1();
      break;
    case '1':
      display_led2();
      break;
    case '2':
      display_led3();
      break;
  }
}

void cmt_bluetooth(void)
{
  //  Bluetoothで受信できるバイト数を取得する
  if(SerialBT.available())
  {
    //  データを受信する
    cmd = SerialBT.read();
  }
}

void display_led1()
{
  //  LED１を点灯する
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, LOW);
}

void display_led2()
{
  //  LED１を点灯する
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, LOW);
  delay(WAIT_TIME);
  //  LED２を点灯する
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, HIGH);
  delay(WAIT_TIME);
}

void display_led3()
{
  for(int i=0; i<2; i++)
  {
    //  LED１を点灯する
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, LOW);
    delay(WAIT_TIME);
    //  LED１を消灯する
    digitalWrite(LED_PIN1, LOW);
    delay(WAIT_TIME);
  }
  //  LED２を点灯する
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, HIGH);
  delay(WAIT_TIME);
}
