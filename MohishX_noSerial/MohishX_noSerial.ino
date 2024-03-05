// MOHISH-X ASL 2024
// MD. JANNATUL NAYEM
// NO SERIAL COMM USED

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

  int ch3 = map(Flip,1060,1900,-300,300);

  int ch4 = map(LR,1090,1930,-300,300);

  int ch5 = map(Dir,1065,1890,0,1);

  digitalWrite(rt,ch5);

  if(ch3 < -100)
  {
    if(ch2 < -150 && mod(ch4) < 100)
    {
      FORWARD();
    }
    if(ch2 < -150 && mod(ch4) > 100 && ch4 < 0)
    {
      F_LEFT();
    }
    if(ch2 < -150 && mod(ch4) > 100 && ch4 > 0)
    {
      F_RIGHT();
    }
    if(ch4 < -150 && mod(ch2) < 100)
    {
      LEFT();
    }
    if(ch4 > 150 && mod(ch2) < 100)
    {
      RIGHT();
    }   
    if(ch2 > 150 && mod(ch4) < 100)
    {
      BACKWARD();
    }
    if(ch2 > 150 && mod(ch4) > 100 && ch4 < 0)
    {
      LEFT_B();
    }
    if(ch2 > 150 && mod(ch4) > 100 && ch4 > 0)
    {
      RIGHT_B();
    }
    if(mod(ch2) < 100 && mod(ch4) < 100)
    {
      NO_MOVE();
    }
  }
  else if(ch3 > 100)
  {
    if(ch2 < -150 && mod(ch4) < 100)
    {
      BACKWARD();
    }
    if(ch2 < -150 && mod(ch4) > 100 && ch4 < 0)
    {
      F_LEFT();
    }
    if(ch2 < -150 && mod(ch4) > 100 && ch4 > 0)
    {
      F_RIGHT();
    }
    if(ch4 < -150 && mod(ch2) < 100)
    {
      RIGHT_R();
    }
    if(ch4 > 150 && mod(ch2) < 100)
    {
      LEFT_R();
    }   
    if(ch2 > 150 && mod(ch4) < 100)
    {
      FORWARD();
    }
    if(ch2 > 150 && mod(ch4) > 100 && ch4 < 0)
    {
      RIGHT_B_R(); 
    }
    if(ch2 > 150 && mod(ch4) > 100 && ch4 > 0)
    {
      LEFT_B_R();    
    }
    if(mod(ch2) < 100 && mod(ch4) < 100)
    {
      NO_MOVE();
    }

  }
  // else {
  //   NO_MOVE();
  // }

}


int mod(int n)
{
  if(n < 0)
    return (n * -1);
  return n;
}
