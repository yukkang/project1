//===  이산화탄소 + 각도  졸음 경보기.  

#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);      



void setup()
{
  pinMode(A3,OUTPUT);         //부져  
  digitalWrite(A3,0);    
  pinMode(A4,INPUT);         //각도센서
  digitalWrite(A4,1);    // 
      
  pinMode(A5,INPUT);         //이산화탄소센서  
  digitalWrite(A5,0);     


  lcd.begin(16, 2);              //LCD 셋트
  lcd.setCursor(0, 0);
  lcd.print("[  SLEEPINESS  ]"); //LCD 윗줄.
 
  lcd.setCursor(16, 0);       //LCD 아래줄
  lcd.print("CO2:    SLOP:OFF");
 
}

void BEEP(void)          //경보음.
{register unsigned int i;
  for(i = 0; i < 255; i++)
  {digitalWrite(A3,1); 
  delayMicroseconds(300);   
   digitalWrite(A3,0); 
   delayMicroseconds(300);  
} }



void loop()
{
  unsigned char CO2 = analogRead(A5); //이산화탄소 읽기.   

  lcd.setCursor(20,0);     //LCD 아래줄 표시위치   
  lcd.print(CO2);      //이산화탄소값 표시.    
  lcd.print("% ");      //%


  lcd.setCursor(29,0);     //LCD 아래줄 표시위치   
 
  if(!(digitalRead(A4)))    //각도센서 읽기.
  
  {lcd.print("ON ");}       //고개 숙이면 온.
  else                   
  {lcd.print("OFF");}       //평시는 오프.
  
  if(!(digitalRead(A4)) && (CO2>30)) 
  BEEP();          //고개숙이고 30%이상시 경보.   


  delay(500); 
