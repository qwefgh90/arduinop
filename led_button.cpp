
#include <Bounce2.h>             //바운싱 현상을 방지하기 위해 이 라이브러리를 사용합니다.
/*
 * 스위치 - (10K 저항+그라운드, 5V, 2번 출력)
 * LED - (220옴 저항+그라운드, 11번 출력)
 * 
 */
 int buttonpin = 2;
 int LED = 11;
 Bounce bouncer = Bounce();    
 
 void setup()
 { 
  pinMode(buttonpin, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  bouncer.attach( buttonpin );
  bouncer.interval(5);
 } 
 
 void loop()
 { 
   if ( bouncer.update() ) {      //버튼이 눌리면
    Serial.println(bouncer.read());
     //int buttoninput = digitalRead(buttonpin);
    //  Serial.println(buttoninput);
     if (bouncer.read() == HIGH)
     {
      digitalWrite(LED, HIGH);
     }
     else
     { 
      digitalWrite(LED, LOW); 
     }
   }
}
