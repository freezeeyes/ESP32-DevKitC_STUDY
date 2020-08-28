//  初期設定
void setup()
{
  //  シリアル通信の通信速度を指定する
  Serial.begin(115200);
}

//  メインプログラム
void loop()
{
  //  文字列を送信する
  Serial.print("Hello ");
  //  ミリ秒指定で１秒間待機する
  delay(1000);
  //  改行付きの文字列を送信する
  Serial.println("World!!");
  //  マイクロ秒指定で１秒間待機する
  delayMicroseconds(1000000);
}
