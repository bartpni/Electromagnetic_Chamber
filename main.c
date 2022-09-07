#include <Arduino.h>

#define X1 22
#define Y1 23
#define X2 26
#define Y2 25
#define Z1 18
#define Z2 19
#define BUTTON 15
#define ADC 2
int analog_value;
int cykl;
int tryb = 0;
int ButtonValue = 0;

void setup() {
  pinMode(X1,OUTPUT);
  pinMode(Y1,OUTPUT);
  pinMode(X2,OUTPUT);
  pinMode(Y2,OUTPUT);
  pinMode(Z1,OUTPUT);
  pinMode(Z2,OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(115200);
}

void loop() {
  analog_value = analogRead(ADC);
  cykl = map(analog_value, 0, 4095, 0, 500);
  ButtonValue = digitalRead(BUTTON);
  Serial.print("Tryb: ");
  Serial.println(tryb);
  Serial.println(ButtonValue);
  Serial.print("Potencjonometr: ");
  Serial.println(analog_value);
  Serial.println(cykl);
  if (ButtonValue == HIGH)
   {
   tryb += 1;
   }
   if (tryb > 8 )
   {
   tryb = 0;
   }


  switch (tryb)
  {
  case 0:  // trajektoria odcinkowa wzdłuż osi x
      digitalWrite(X1,HIGH);
      delay(cykl);
      digitalWrite(X1,LOW);
      digitalWrite(X2,HIGH);
      delay(cykl);
      digitalWrite(X2,LOW);
    break;
  case 1:  // trajektoria odcinkowa wzdłuż osi y
      digitalWrite(Y1,HIGH);
      delay(cykl);
      digitalWrite(Y1,LOW);
      digitalWrite(Y2,HIGH);
      delay(cykl);
      digitalWrite(Y2,LOW);
    break;
  case 2: // trajektoria odcinkowa wzdłuż osi z
      digitalWrite(Z1,HIGH);
      delay(cykl);
      digitalWrite(Z1,LOW);
      digitalWrite(Z2,HIGH);
      delay(cykl);
      digitalWrite(Z2,LOW);
    break;
  case 3:   // Trajektoria kwadratowa w płaszczyźnie xz
      digitalWrite(Y1,HIGH);
      delay(cykl);
      digitalWrite(Y1,LOW);
      digitalWrite(Z1,HIGH);
      delay(cykl);
      digitalWrite(Z1,LOW);
      digitalWrite(Y2,HIGH);
      delay(cykl);
      digitalWrite(Y2,LOW);
      digitalWrite(Z2,HIGH);
      delay(cykl);
      digitalWrite(Z2,LOW);
    break;
  case 4:   // Trajektoria kwadratowa w płaszczyźnie xy
      digitalWrite(X1,HIGH);
      delay(cykl);
      digitalWrite(X1,LOW);
      digitalWrite(Y1,HIGH);
      delay(cykl);
      digitalWrite(Y1,LOW);
      digitalWrite(X2,HIGH);
      delay(cykl);
      digitalWrite(X2,LOW);
      digitalWrite(Y2,HIGH);
      delay(cykl);
      digitalWrite(Y2,LOW);
    break;
  case 5:  // Trajektoria kwadratowa w płaszczyźnie yz
      digitalWrite(X1,HIGH);
      delay(cykl);
      digitalWrite(X1,LOW);
      digitalWrite(Z1,HIGH);
      delay(cykl);
      digitalWrite(Z1,LOW);
      digitalWrite(X2,HIGH);
      delay(cykl);
      digitalWrite(X2,LOW);
      digitalWrite(Z2,HIGH);
      delay(cykl);
      digitalWrite(Z2,LOW);
    break;
  case 6:  // Trajektoria kwadratowa z przekątną
      digitalWrite(X2,HIGH);
      delay(cykl);
      digitalWrite(X2,LOW);
      digitalWrite(Z1,HIGH);
      delay(cykl);
      digitalWrite(Z1,LOW);
      digitalWrite(X1,HIGH);
      delay(cykl);
      digitalWrite(X1,LOW);
      digitalWrite(X2,HIGH);
      delay(cykl);
      digitalWrite(X2,LOW);
      digitalWrite(Z2,HIGH);
      delay(cykl);
      digitalWrite(Z2,LOW);
      digitalWrite(X1,HIGH);
      delay(cykl);
      digitalWrite(X1,LOW);
    break;
  case 7:  //  Trajektoria w postaci „płaskiej ósemki
      digitalWrite(X2,HIGH);
      delay(cykl);
      digitalWrite(X2,LOW);
      digitalWrite(Z1,HIGH);
      delay(cykl);
      digitalWrite(Z1,LOW);
      digitalWrite(Z2,HIGH);
      delay(cykl);
      digitalWrite(Z2,LOW);
      digitalWrite(X1,HIGH);
      delay(cykl);
      digitalWrite(X1,LOW);
    break;
  case 8:  // Trajektoria w postaci „przestrzennej ósemki”
      digitalWrite(X2,HIGH);
      delay(cykl);
      digitalWrite(X2,LOW);
      digitalWrite(Z1,HIGH);
      delay(cykl);
      digitalWrite(Z1,LOW);
      digitalWrite(Y1,HIGH);
      delay(cykl);
      digitalWrite(Y1,LOW);
      digitalWrite(Y2,HIGH);
      delay(cykl);
      digitalWrite(Y2,LOW);
      digitalWrite(Z2,HIGH);
      delay(cykl);
      digitalWrite(Z2,LOW);
      digitalWrite(X1,HIGH);
      delay(cykl);
      digitalWrite(X1,LOW);
    break;
  default:
    break;
  }

}