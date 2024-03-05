// MOHISH-X ASL 2024
// MD. JANNATUL NAYEM

#define t3    2 // MotorA+
#define t4    4 // MotorA-
#define t1   A0 // MotorB+
#define t2   A1 // MotorB-

#define rt    8 // swap-relay

#define c2   11 // channel 2
#define c3   10 // channel 3
#define c4    9 // channel 4
#define c5   12 // channel 5

void setup() 
{
  pinMode(t1,OUTPUT);
  pinMode(t2,OUTPUT);
  pinMode(t3,OUTPUT);
  pinMode(t4,OUTPUT);
  pinMode(rt,OUTPUT);
  Serial.begin(9600);
}

void NO_MOVE()
{
  digitalWrite(t1,LOW);
  digitalWrite(t2,LOW);
  digitalWrite(t3,LOW);
  digitalWrite(t4,LOW);
}

void FORWARD()
{
  digitalWrite(t1,LOW);
  digitalWrite(t2,HIGH);
  digitalWrite(t3,LOW);
  digitalWrite(t4,HIGH);
}

void BACKWARD()
{
  digitalWrite(t1,HIGH);
  digitalWrite(t2,LOW);
  digitalWrite(t3,HIGH);
  digitalWrite(t4,LOW);
}

void LEFT()
{
  digitalWrite(t1,LOW);
  digitalWrite(t2,LOW);
  digitalWrite(t3,LOW);
  digitalWrite(t4,HIGH);
}

void LEFT_R()
{
  digitalWrite(t1,LOW);
  digitalWrite(t2,LOW);
  digitalWrite(t3,HIGH);
  digitalWrite(t4,LOW);
}

void RIGHT()
{
  digitalWrite(t1,LOW);
  digitalWrite(t2,HIGH);
  digitalWrite(t3,LOW);
  digitalWrite(t4,LOW);
}

void RIGHT_R()
{
  digitalWrite(t1,HIGH);
  digitalWrite(t2,LOW);
  digitalWrite(t3,LOW);
  digitalWrite(t4,LOW);
}

void F_LEFT()
{
  digitalWrite(t1,HIGH);
  digitalWrite(t2,LOW);
  digitalWrite(t3,LOW);
  digitalWrite(t4,HIGH);
}

void F_RIGHT()
{
  digitalWrite(t1,LOW);
  digitalWrite(t2,HIGH);
  digitalWrite(t3,HIGH);
  digitalWrite(t4,LOW);
}

void RIGHT_B()
{
  digitalWrite(t1,HIGH);
  digitalWrite(t2,LOW);
  digitalWrite(t3,LOW);
  digitalWrite(t4,LOW);
}

void RIGHT_B_R()
{
  digitalWrite(t1,LOW);
  digitalWrite(t2,HIGH);
  digitalWrite(t3,LOW);
  digitalWrite(t4,LOW);
}

void LEFT_B()
{
  digitalWrite(t1,LOW);
  digitalWrite(t2,LOW);
  digitalWrite(t3,HIGH);
  digitalWrite(t4,LOW);
}

void LEFT_B_R()
{
  digitalWrite(t1,LOW);
  digitalWrite(t2,LOW);
  digitalWrite(t3,LOW);
  digitalWrite(t4,HIGH);
}

void loop() 
{
  int FB = pulseIn(c2, HIGH, 25000);
  int LR = pulseIn(c4,HIGH,25000);
  int Flip = pulseIn(c3,HIGH,25000);
  int Dir = pulseIn(c5,HIGH,25000);

  int ch2 = map(FB, 1060,1900,-300,300); 
  Serial.print("ch2 FB:  ");
  Serial.print(ch2);
  Serial.print("   ");

  int ch3 = map(Flip,1060,1900,-300,300);
  Serial.print("ch3 Flip :  ");
  Serial.print(ch3);
  Serial.print("   ");

  int ch4 = map(LR,1090,1930,-300,300);
  Serial.print("ch4 LR:  ");
  Serial.print(ch4);
  Serial.print("   ");

  int ch5 = map(Dir,1065,1890,0,1);
  Serial.print("ch5 Dir:  ");
  Serial.print(ch5);
  Serial.print("   ");

  digitalWrite(rt,ch5);

  if(ch3 < -100)
  {
    if(ch2 < -150 && mod(ch4) < 100)
    {
      FORWARD();
      Serial.print("FORWARD");
    }
    if(ch2 < -150 && mod(ch4) > 100 && ch4 < 0)
    {
      F_LEFT();
      Serial.print("F_LEFT");
    }
    if(ch2 < -150 && mod(ch4) > 100 && ch4 > 0)
    {
      F_RIGHT();
      Serial.print("F_RIGHT");
    }
    if(ch4 < -150 && mod(ch2) < 100)
    {
      LEFT();
      Serial.print("LEFT");
    }
    if(ch4 > 150 && mod(ch2) < 100)
    {
      RIGHT();
      Serial.print("RIGHT");
    }   
    if(ch2 > 150 && mod(ch4) < 100)
    {
      BACKWARD();
      Serial.print("BACKWARD");
    }
    if(ch2 > 150 && mod(ch4) > 100 && ch4 < 0)
    {
      LEFT_B();
      Serial.print("LEFT_B");
    }
    if(ch2 > 150 && mod(ch4) > 100 && ch4 > 0)
    {
      RIGHT_B();
      Serial.print("RIGHT_B");
    }
    if(mod(ch2) < 100 && mod(ch4) < 100)
    {
      NO_MOVE();
      Serial.print("NO_MOVEMENT");
    }
  }
  else if(ch3 > 100)
  {
    if(ch2 < -150 && mod(ch4) < 100)
    {
      BACKWARD();
      Serial.print("FORWARD");
    }
    if(ch2 < -150 && mod(ch4) > 100 && ch4 < 0)
    {
      F_LEFT();
      Serial.print("F_LEFT");
    }
    if(ch2 < -150 && mod(ch4) > 100 && ch4 > 0)
    {
      F_RIGHT();
      Serial.print("F_RIGHT");
    }
    if(ch4 < -150 && mod(ch2) < 100)
    {
      RIGHT_R();
      Serial.print("LEFT");
    }
    if(ch4 > 150 && mod(ch2) < 100)
    {
      LEFT_R();
      Serial.print("RIGHT");
    }   
    if(ch2 > 150 && mod(ch4) < 100)
    {
      FORWARD();
      Serial.print("BACKWARD");
    }
    if(ch2 > 150 && mod(ch4) > 100 && ch4 < 0)
    {
      RIGHT_B_R();
      Serial.print("LEFT_B");    
    }
    if(ch2 > 150 && mod(ch4) > 100 && ch4 > 0)
    {
      LEFT_B_R();
      Serial.print("RIGHT_B");      
    }
    if(mod(ch2) < 100 && mod(ch4) < 100)
    {
      NO_MOVE();
      Serial.print("NO_MOVEMENT");
    }

  }
  // else {
  //   NO_MOVE();
  //   Serial.print("INVALID_MOVE!");
  // }
  Serial.println();
}


int mod(int n)
{
  if(n < 0)
    return (n * -1);
  return n;
}
