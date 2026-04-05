#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int potPin = A0;

int green = 8;
int yellow = 9;
int red = 10;
int buzzer = 11;

void setup() {
  lcd.begin(16, 2);

  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int value = analogRead(potPin);

  // Convert analog value to BPM (realistic range)
  int bpm = map(value, 0, 1023, 40, 140);

  lcd.clear();

  // Display BPM
  lcd.setCursor(0, 0);
  lcd.print("Heart Rate:");
  lcd.setCursor(0, 1);
  lcd.print(bpm);
  if (bpm != 72)
    lcd.print(" BPM");
  else
    lcd.print(" BPM (PERFECT)");

  // Condition logic
  if (bpm < 60) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(buzzer, HIGH);
  }
  else if (bpm >= 60 && bpm <= 100) {
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(buzzer, LOW);
  }
  else {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  delay(500);
}