/*************************************************************
 * TITLE: タイマー割り込みのプログラム１
 * DESCRIPTION:
 *     割り込み処理でシリアルモニタに文字列を表示する
 *************************************************************/


#include <uTimerLib.h>

bool flag = false;
int counter = 0;

void serial_print(void);

void setup()
{
  //  シリアル通信の通信速度を指定する
  Serial.begin(115200);
  //  １秒間隔のタイマー割り込みを開始する
  TimerLib.setInterval_s(serial_print, 1);
}

void loop()
{
  //  約５秒経過したらタイマー割り込みを停止する
  if(counter==5)
  {
    TimerLib.clearTimer();
  }
}

void serial_print(void)
{
  //  タイマーの経過時間をカウントする
  counter++;
  //  シリアルモニタに表示するメッセージを切り替える
  flag = flag ? false : true;
  Serial.println(flag ? "true" : "false");
}
