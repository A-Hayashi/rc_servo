#include <Wire.h>
#include "VarSpeedServo.h"

// create servo object to control a servo
VarSpeedServo myservo1;
VarSpeedServo myservo2;
VarSpeedServo myservo3;
VarSpeedServo myservo4;
VarSpeedServo myservo5;
VarSpeedServo myservo6;
VarSpeedServo myservo7;
VarSpeedServo myservo8;

void setup() {
  Serial.begin(9600);
  Serial.println("Servo Start");
  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  myservo5.attach(6);
  myservo6.attach(7);
  myservo7.attach(8);
  myservo8.attach(9);
  i2c_init();
}

void loop() {
//  myservo1.write(0, 40);
//  delay(2000);
//
//  myservo1.write(90, 40);
//  delay(2000);
//
//  myservo1.write(180, 80);
//  delay(2000);
//
//  myservo1.write(90, 40);
//  delay(2000);
}

void i2c_init()
{
  Wire.begin(0x25) ;                 // Ｉ２Ｃの初期化、自アドレスを0x20とする
  Wire.onRequest(requestEvent);     // マスタからのデータ取得要求のコールバック関数登録
  Wire.onReceive(receiveEvent);     // マスタからのデータ送信対応のコールバック関数登録
}

void receiveEvent(int howMany) {
  Serial.println("receiveEvent");
  byte cmd = Wire.read();
  Serial.print("cmd:");
  Serial.println(cmd);

  if (cmd == 0x01) {
    if (howMany == 4) {
      byte servo = Wire.read();
      byte angle = Wire.read();
      byte speed = Wire.read();
      Serial.print("servo: ");
      Serial.print(servo);
      Serial.print(" angle: ");
      Serial.print(angle);
      Serial.print(" speed: ");
      Serial.println(speed);
      switch (servo) {
        case 1:
          myservo1.write(angle, speed);
          break;
        case 2:
          myservo2.write(angle, speed);
          break;
        case 3:
          myservo3.write(angle, speed);
          break;
        case 4:
          myservo4.write(angle, speed);
          break;
        case 5:
          myservo5.write(angle, speed);
          break;
        case 6:
          myservo6.write(angle, speed);
          break;
        case 7:
          myservo7.write(angle, speed);
          break;
        case 8:
          myservo8.write(angle, speed);
          break;
        default:
          break;
      }
    }
  }

  if (cmd == 0x02) {
    if (howMany == 2) {
      byte servo = Wire.read();
      Serial.print("servo: ");
      Serial.print(servo);
      Serial.println(" detach");
      switch (servo) {
        case 1:
          myservo1.detach();
          break;
        case 2:
          myservo2.detach();
          break;
        case 3:
          myservo3.detach();
          break;
        case 4:
          myservo4.detach();
          break;
        case 5:
          myservo5.detach();
          break;
        case 6:
          myservo6.detach();
          break;
        case 7:
          myservo7.detach();
          break;
        case 8:
          myservo8.detach();
          break;
        default:
          break;
      }
    }
  }

  if (cmd == 0x03) {
    if (howMany == 2) {
      byte servo = Wire.read();
      Serial.print("servo: ");
      Serial.print(servo);
      Serial.println(" attach");
      switch (servo) {
        case 1:
          myservo1.attach(2);
          break;
        case 2:
          myservo2.attach(3);
          break;
        case 3:
          myservo3.attach(4);
          break;
        case 4:
          myservo4.attach(5);
          break;
        case 5:
          myservo5.attach(6);
          break;
        case 6:
          myservo6.attach(7);
          break;
        case 7:
          myservo7.attach(8);
          break;
        case 8:
          myservo8.attach(9);
          break;
        default:
          break;
      }
    }
  }
}

// マスターからのリクエストに対するデータ送信
void requestEvent() {
  Serial.println("requestEvent");
}


