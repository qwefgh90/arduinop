#include <math.h>
/*
 * LM35 - (1번 아날로그 입력, 5V, 그라운드)
 * 
 */
 int buttonpin = 2;
 int LED = 11;
  struct State{
    int temp = 0;
  
  };
 State state;
 
 void setup()
 { 
  Serial.begin(9600);
 } 
 
 void loop()
 { 
    int val; // 
    int dat; //define variable 
    val=analogRead(0); // read the analog value and assign to val 
    dat=(125*val)>>8; //temperature calculation formula 
    
    if(abs(dat - state.temp) >= 1){
     state.temp = dat;
     Serial.print("Tep:"); 
     Serial.print(dat);//output dat value 
     Serial.println("C"); //output character string C 
    }
}
