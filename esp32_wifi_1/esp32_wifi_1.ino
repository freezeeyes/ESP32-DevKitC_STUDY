#include <WiFi.h>

void setup()
{
  //  シリアル通信の通信速度を指定する
  Serial.begin(115200);
  //  TODO: あなたのWiFi環境のSSIDとパスワードを指定してください
  //  WiFiに接続するSSIDとパスワードを指定する
  WiFi.begin("", "");
  //  WiFiの接続状態を100ミリ秒間隔で確認する
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(100);
  }
  //  WiFiの接続完了メッセージをシリアルモニタに表示する
  Serial.println("WiFi Connected!!");
  //  IPアドレスをシリアルモニタに表示する
  Serial.println(WiFi.localIP());
}

void loop()
{
}
