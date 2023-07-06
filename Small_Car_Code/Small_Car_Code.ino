#define IN1  8
#define IN2  7
#define IN3  11
#define IN4  12
#define ENA  10
#define ENB  9

void forward();
void backward();
void right();
void left();
void Stop();

char input;
unsigned int Speed1 = 100;
unsigned int Speed2 = 80;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(IN1,  OUTPUT);
  pinMode(IN2,  OUTPUT);
  pinMode(IN3,  OUTPUT);
  pinMode(IN4,  OUTPUT);

  pinMode(ENA,  OUTPUT);
  pinMode(ENB,  OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    input = Serial.read();

    if(input == 'F')
    {
      forward();
    }
    else if(input == 'B')
    {
      backward();
    }
    else if(input == 'R')
    {
      right();
    }
    else if(input == 'L')
    {
      left();
    }
    else if(input == 'U')
    {
      Speed1 += 10;
      Speed2 += 10;
    }
    else if(input == 'D')
    {
      Speed1 -= 10;
      Speed2 -= 10;
    }
    else 
    {
      Stop();
    }

  }
}

void right()
{
  analogWrite(ENA,Speed2); analogWrite(ENB,Speed1);
  digitalWrite(IN1,HIGH); digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH); digitalWrite(IN4,LOW);
}

void left()
{
  analogWrite(ENA,Speed2); analogWrite(ENB,Speed1);
  digitalWrite(IN1,LOW); digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW); digitalWrite(IN4,HIGH);
}

void Stop()
{
  analogWrite(ENA,0); analogWrite(ENB,0);
  digitalWrite(IN1,LOW); digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW); digitalWrite(IN4,LOW);
}

void backward()
{
  analogWrite(ENA,Speed2); analogWrite(ENB,Speed1);
  digitalWrite(IN1,HIGH); digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW); digitalWrite(IN4,HIGH);
}

void forward()
{
  analogWrite(ENA,Speed2); analogWrite(ENB,Speed1);
  digitalWrite(IN1,LOW); digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH); digitalWrite(IN4,LOW);
}
