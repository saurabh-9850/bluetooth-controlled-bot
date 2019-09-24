#include <Servo.h>
const int leftmotor1 = 13;
const int leftmotor2 = 12;
const int rightmotor1 = 11;
const int rightmotor2 = 10;

const int back1 = 9;
const int back2 = 8;

int pos =0;

Servo myservo;


void setup()
{
   
    pinMode(rightmotor1,OUTPUT);
    pinMode(rightmotor2,OUTPUT);
   
    pinMode(leftmotor1,OUTPUT);
    pinMode(leftmotor2,OUTPUT);
   
    pinMode(back1,OUTPUT);
    pinMode(back2,OUTPUT);
   
    Serial.begin(9600);
    myservo.attach(3);
}
void loop()
{
   if (Serial.available() >0)
    {
        char dir=Serial.read();
        Serial.println(dir);
         
        if(dir == 'F' )
        {
          forward();
        }
       else if(dir == 'B' )
        {
          backward();
        }
     else  if(dir == 'L' )
        {
          left();
        }
        else if(dir == 'R' )
        {
          right();
        }



        else if(dir == 'H' )
        {
          bleft();
        }
        else if(dir == 'J' )
        {
          bright();
        }
        else if(dir == 'V')
        {
          flapon();
        }

        else if(dir == 'v')
        {
        flapoff();
        }

        else if(dir== 'W')
        {
        flaponn();
        }
        else if(dir== 'w')
        {
        flapofff();
        }

        else
        motorstop();
         
       
   
       
    }
   

   
   
}
///////////////////////////////1
void forward(void)
{
digitalWrite(rightmotor1,HIGH);
digitalWrite(rightmotor2,LOW);

digitalWrite(leftmotor1,HIGH);
digitalWrite(leftmotor2,LOW);

digitalWrite(back1,HIGH);
digitalWrite(back2,LOW);
    myservo.write(0);
}
///////////////////////////////2
void backward(void)
{
digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,HIGH);

digitalWrite(leftmotor1,LOW);
digitalWrite(leftmotor2,HIGH);

digitalWrite(back1,LOW);
digitalWrite(back2,HIGH);
    myservo.write(0);
   
}
///////////////////////////////3
void left(void)
{
digitalWrite(rightmotor1,HIGH);
digitalWrite(rightmotor2,LOW);

digitalWrite(leftmotor1,LOW);
digitalWrite(leftmotor2,LOW);

digitalWrite(back1,HIGH);
digitalWrite(back2,LOW);
     myservo.write(0);
}
///////////////////////////////4
void right(void)
{
digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,LOW);

digitalWrite(leftmotor1,HIGH);
digitalWrite(leftmotor2,LOW);

digitalWrite(back1,HIGH);
digitalWrite(back2,LOW);
   
 myservo.write(0);
}
///////////////////////////////5
void bleft(void)
{
digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,HIGH);

digitalWrite(leftmotor1,LOW);
digitalWrite(leftmotor2,LOW);

digitalWrite(back1,LOW);
digitalWrite(back2,HIGH);
   myservo.write(0);
}
///////////////////////////////6
void bright(void)
{
digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,LOW);

digitalWrite(leftmotor1,LOW);
digitalWrite(leftmotor2,HIGH);

digitalWrite(back1,LOW);
digitalWrite(back2,HIGH);
     myservo.write(0);
}
///////////////////////////////7
void flapon(void)
{
digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,LOW);

digitalWrite(leftmotor1,LOW);
digitalWrite(leftmotor2,LOW);

digitalWrite(back1,LOW);
digitalWrite(back2,LOW);
   
for(pos=0;pos<=90;pos+=1)
    {
        myservo.write(pos);
        delay(8);
    }
for(pos=90;pos>=0;pos-=1)
    {
        myservo.write(pos);
        delay(15);
    }
}

///////////////////////////////8
void flapoff(void)
{
digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,LOW);

digitalWrite(leftmotor1,LOW);
digitalWrite(leftmotor2,LOW);

digitalWrite(back1,LOW);
digitalWrite(back2,LOW);
    for(pos=0;pos<=90;pos+=1)
    {
        myservo.write(0);
        delay(8);
    }
for(pos=90;pos>=0;pos-=1)
    {
        myservo.write(0);
        delay(15);
    }
}
///////////////////////////////9
void flaponn(void)
{
digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,LOW);

digitalWrite(leftmotor1,LOW);
digitalWrite(leftmotor2,LOW);

digitalWrite(back1,LOW);
digitalWrite(back2,LOW);
   
    for(pos=0;pos<=90;pos+=1)
    {
        myservo.write(pos);
        delay(8);
    }
   
   
}
///////////////////////////////10
void flapofff(void)
{
digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,LOW);

digitalWrite(leftmotor1,LOW);
digitalWrite(leftmotor2,LOW);

digitalWrite(back1,LOW);
digitalWrite(back2,LOW);
    for(pos=90;pos>=0;pos-=1)
    {
        myservo.write(pos);
        delay(15);
    }
}
///////////////////////////////11
void motorstop(void)
{
digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,LOW);

digitalWrite(leftmotor1,LOW);
digitalWrite(leftmotor2,LOW);

digitalWrite(back1,LOW);
digitalWrite(back2,LOW);
   
    servostop();
}
void servostop(void)
{
   

myservo.write(0);

}
