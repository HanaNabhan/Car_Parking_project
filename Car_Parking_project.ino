

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Servo.h>
#define ldr A1
#define leds A5
#define temperature A0
#define buzzer A3
Servo servofigthers;
#define g 2
#define f 3
#define a 4
#define b 5
#define e 6
#define d 7
#define c 8
#define D 13
void gate();
void Ldr();
void temp();
void segment(int);
int h = 0;
int IR1 = 12;
int IR2 = 11;

int x = 0;
int y = 0;

int Slot = 5;
int flag1 = 0;
int flag2 = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  servofigthers.attach(10);
  servofigthers.write(100);

  lcd.setCursor(0, 0);
  lcd.print("     ARDUINO    ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING SYSTEM ");
  delay(2000);
  lcd.clear();
  pinMode(ldr, INPUT);
  pinMode(leds, OUTPUT);
}

void loop() {
  if (digitalRead(IR1) == LOW && flag1 == 0) {
    if (Slot > 0) {
      flag1 = 1;
      if (flag2 == 0) {
        servofigthers.write(0);
        Slot = Slot - 1;
      }
    } else {
      lcd.setCursor(0, 0);
      lcd.print("    SORRY :(    ");
      lcd.setCursor(0, 1);
      lcd.print("  Parking Full  ");
      delay(3000);
      lcd.clear();
    }
  }

  if (digitalRead(IR2) == LOW && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      servofigthers.write(0);
      Slot = Slot + 1;
    }
  }

  if (flag1 == 1 && flag2 == 1) {
    delay(1000);
    servofigthers.write(100);
    flag1 = 0, flag2 = 0;


    lcd.setCursor(0, 0);
    lcd.print("    WELCOME!    ");
    lcd.setCursor(0, 1);
    lcd.print("Slot Left: ");
    lcd.print(Slot);
  }
  segment(Slot);
  Serial.println(Slot);
}



void segment(int i) {
  pinMode(g, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  switch (i) {
    case 0:
      digitalWrite(c, 1);
      digitalWrite(g, 0);
      digitalWrite(f, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(b, 1);
      digitalWrite(a, 1);
      break;
    case 1:
      digitalWrite(c, 1);
      digitalWrite(g, 0);
      digitalWrite(f, 0);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(b, 1);
      digitalWrite(a, 0);
      break;
    case 2:
      digitalWrite(c, 0);
      digitalWrite(g, 1);
      digitalWrite(f, 0);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(b, 1);
      digitalWrite(a, 1);
      break;
    case 3:
      digitalWrite(c, 1);
      digitalWrite(g, 1);
      digitalWrite(f, 0);
      digitalWrite(d, 1);
      digitalWrite(e, 0);
      digitalWrite(b, 1);
      digitalWrite(a, 1);
      break;
    case 4:
      digitalWrite(c, 1);
      digitalWrite(g, 1);
      digitalWrite(f, 1);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(b, 1);
      digitalWrite(a, 0);
      break;
    case 5:
      digitalWrite(c, 1);
      digitalWrite(g, 1);
      digitalWrite(f, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 0);
      digitalWrite(b, 0);
      digitalWrite(a, 1);
      break;
  }
}
/*void gate (){
  
  
}*/
void Ldr() {

  x = analogRead(ldr);
  Serial.println(x);
  y = map(x, 10, 1000, 0, 255);
  analogWrite(leds, y);
}
void temp() {
  digitalWrite(D, LOW);
  int Temp = analogRead(temperature);
  float volts = (Temp / 965.0) * 5;
  float celcius = (volts - 0.5) * 100;
  float fahrenheit = (celcius * 9 / 5 + 32);
  Serial.println(fahrenheit);
  lcd.setCursor(5, 0);
  lcd.print(" Temp = ");
  lcd.print(fahrenheit);
  lcd.print("  fahrenheit ");
  delay(2000);
  if (celcius > 40) {
    tone(buzzer, 1000);
    delay(1000);
    noTone(buzzer);
    delay(1000);
  }
}