int switch_1=13;
int switch_2=12;
int motor_1=7;
int motor_2=8;
int potentiometer_1=A1;
int potentiometer_2=A5;

void setup()
{
  pinMode(switch_1,0);
  pinMode(switch_2,0);
  pinMode(motor_1,1);
  pinMode(motor_2,1);
  Serial.begin(9600);
}

void loop()
{
  int high1=digitalRead(switch_1);
  int high2=digitalRead(switch_2);
  int readingpt_1=map(analogRead(potentiometer_1),0,1023,0,255);
  int readingpt_2=map(analogRead(potentiometer_2),0,1023,0,255);
  
                      
  if (high1==1 && high2==0)
  {
    analogWrite(motor_1,readingpt_1);
    analogWrite(motor_2,0);
  }
  else if(high2==1 && high1==0)
  {
    analogWrite(motor_2,readingpt_2);
    analogWrite(motor_1,0);
  }
  else if(high1==1 && high2==1)
  {
    analogWrite(motor_1,readingpt_1);
    analogWrite(motor_2,readingpt_2);
  }
  else if(high1==0 && high2==0)
  {
    analogWrite(motor_1,0);
    analogWrite(motor_2,0);
  }
  if(Serial.available())
  {
    char reading=Serial.read();
    if(reading=='R'){
      analogWrite(motor_1,readingpt_1);
    }
    else if(reading=='L'){
      analogWrite(motor_2,readingpt_2);
    }
    else if(reading=='S'){
      analogWrite(motor_1,0);
      analogWrite(motor_2,0);
    }
  }                                       
}
