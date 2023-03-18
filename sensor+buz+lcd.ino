#include <LiquidCrystal.h>
#include "SR04.h"
#include "pitches.h"
SR04 sr04 = SR04(2,4);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int melody[] = {NOTE_C6};
int duration = 500;
int ledPinwi = 40;
int ledPingr = 34;
int ledPinylw = 30;
int ledPinred = 26;
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(ledPinwi, OUTPUT);
  pinMode(ledPingr, OUTPUT);
  pinMode(ledPinylw, OUTPUT);
  pinMode(ledPinred, OUTPUT);

}

int previousValue = 0;

void loop() {
  int currentValue = sr04.Distance();
  if (currentValue != previousValue){
  lcd.clear();
  lcd.print(currentValue);
  lcd.print("cm");
  previousValue = currentValue;
  }
  int thisNote = 0;
    if (currentValue > 30){
      digitalWrite(ledPinwi, LOW);
      digitalWrite(ledPingr, LOW);
      digitalWrite(ledPinylw, LOW);
      digitalWrite(ledPinred, LOW);      
    }
    if (currentValue >= 20 && currentValue <= 30){
      digitalWrite(ledPinwi, HIGH);
      digitalWrite(ledPingr, LOW);
      digitalWrite(ledPinylw, LOW);
      digitalWrite(ledPinred, LOW);
      tone(6, melody[thisNote], duration);
      delay(2000);
    }
    if (currentValue > 15 && currentValue < 20){
      digitalWrite(ledPinwi, LOW);
      digitalWrite(ledPingr, HIGH);
      digitalWrite(ledPinylw, LOW);
      digitalWrite(ledPinred, LOW);
      tone(6, melody[thisNote], duration);
      delay(1500);
    } 
    if (currentValue > 5 && currentValue < 15){
      digitalWrite(ledPinwi, LOW);
      digitalWrite(ledPingr, LOW);
      digitalWrite(ledPinylw, HIGH);
      digitalWrite(ledPinred, LOW);
      tone(6, melody[thisNote], duration);
      delay(1200);
    }
    if (currentValue <= 5){
      digitalWrite(ledPinwi, LOW);
      digitalWrite(ledPingr, LOW);
      digitalWrite(ledPinylw, LOW);
      digitalWrite(ledPinred, HIGH);
      tone(6, melody[thisNote], duration);
      delay(700);
    }

  delay(20);
}

