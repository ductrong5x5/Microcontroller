#include <LiquidCrystal.h>

// C++ code
//
LiquidCrystal LCD(12,11,5,4,3,2);

void setup()
{
  LCD.begin(16,2);
}

void loop()
{
  
  for(float pos=0;pos<16;pos ++){
  	LCD.setCursor(pos,0); LCD.print("-");
    LCD.setCursor(12,1); LCD.print(static_cast<int>(((pos+1)/16)*100));
  	LCD.setCursor(15,1); LCD.print("%");
    delay(1000);
   }
  LCD.clear();
}