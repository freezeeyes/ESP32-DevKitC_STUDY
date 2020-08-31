/*************************************************************
 * TITLE: タイマー割り込みのプログラム２
 * DESCRIPTION:
 *     割り込み処理でLEDの点灯と消灯を交互に切り替える
 *************************************************************/


#include <uTimerLib.h>

#define HIGH (1)
#define LOW (0)
#define LED_PIN 22

int flag = LOW;
int counter = 0;

void toggle_led(void);

void setup()
{
  //  LED用のピンを出力モードに指定する
  pinMode(LED_PIN, OUTPUT);
  //  １秒間隔のタイマー割り込みを開始する
  TimerLib.setInterval_s(toggle_led, 1);
}

void loop()
{
  //  約１０秒経過したらタイマー割り込みを停止する
  if(counter==10)
  {
    TimerLib.clearTimer();
  }
}

void toggle_led(void)
{
  //  タイマーの経過時間をカウントする
  counter++;
  //  LEDの点灯状態を切り替える
  flag = flag ? LOW : HIGH;
  digitalWrite(LED_PIN, flag);
}
