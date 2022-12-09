#include <LiquidCrystal.h>

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);
int trig = 6;
int echo = 7;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10, INPUT);
  lcd_1.begin(16, 2);
  lcd_1.setCursor(2,0);
  lcd_1.print("HAK");
  lcd_1.setCursor(10,0);
  lcd_1.print("PUAN");
}

// HAK mean Right and puan mean point
int hak=0, puan=0;

void loop() {

  while (hak < 3)
  {
   //----add Right whit Ficical Buttonu----
   int button = digitalRead(13);
   if (button == 1){
      hak += 1;
      digitalWrite(9,1);
      delay(250);
      digitalWrite(9,0);
      delay(300);}
  //-----add Right whit Application Buttonu-------
  if(Serial.available()){
    char deger = Serial.read();
    if(deger == '1'){
      hak += 1;
      digitalWrite(9,1);
      delay(250);
      digitalWrite(9,0);}
    }
      
   //-----Distance Calculation and Adding POINTS to Distance-------------
   digitalWrite(trig,1);//Trig
   delay(1);
   digitalWrite(trig,0);
   int sure = pulseIn(echo,1);
   int mesafe = (sure/2)/28.97;
   int msf = round(mesafe);

    if(msf <= 10)
    {  puan += 30;
       digitalWrite(8,1);
       hak += 1;
       delay(1000);
       digitalWrite(8,0);
       
    }
   else if(msf <= 15)
    {  puan += 15;
       digitalWrite(8,1);
       hak += 1;
       delay(1000);
       digitalWrite(8,0);
    }
  //-----------------------------------

   lcd_1.setCursor(3,1);
   lcd_1.print(hak);
   lcd_1.setCursor(11,1);
   lcd_1.print(puan);
  
  }

  Serial.println(puan);
  lcd_1.clear();
  lcd_1.setCursor(5,0);
  lcd_1.print("SONUC");
  lcd_1.setCursor(7,1);
  lcd_1.print(puan);
delay(1000);
}
