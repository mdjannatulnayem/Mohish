// MOHISH-X ASL 2024
// MD. JANNATUL NAYEM
// NO SERIAL COMM USED
// MINIMAL FUNCTION CALL FOCUSED

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
      // FORWARD
      digitalWrite(t1,LOW);
      digitalWrite(t2,HIGH);
      digitalWrite(t3,LOW);
      digitalWrite(t4,HIGH);
    }
    else if(ch2 < -150 && mod(ch4) > 100 && ch4 < 0)
    {
      // F_LEFT
      digitalWrite(t1,HIGH);
      digitalWrite(t2,LOW);
      digitalWrite(t3,LOW);
      digitalWrite(t4,HIGH);
    }
    else if(ch2 < -150 && mod(ch4) > 100 && ch4 > 0)
    {
      // F_RIGHT
      digitalWrite(t1,LOW);
      digitalWrite(t2,HIGH);
      digitalWrite(t3,HIGH);
      digitalWrite(t4,LOW);
    }
    else if(ch4 < -150 && mod(ch2) < 100)
    {
      // LEFT
      digitalWrite(t1,LOW);
      digitalWrite(t2,LOW);
      digitalWrite(t3,LOW);
      digitalWrite(t4,HIGH);
    }
    else if(ch4 > 150 && mod(ch2) < 100)
    {
      // RIGHT
      digitalWrite(t1,LOW);
      digitalWrite(t2,HIGH);
      digitalWrite(t3,LOW);
      digitalWrite(t4,LOW);
    }   
    else if(ch2 > 150 && mod(ch4) < 100)
    {
      // BACKWARD
      digitalWrite(t1,HIGH);
      digitalWrite(t2,LOW);
      digitalWrite(t3,HIGH);
      digitalWrite(t4,LOW);
    }
    else if(ch2 > 150 && mod(ch4) > 100 && ch4 < 0)
    {
      // LEFT_B
      digitalWrite(t1,LOW);
      digitalWrite(t2,LOW);
      digitalWrite(t3,HIGH);
      digitalWrite(t4,LOW);
    }
    else if(ch2 > 150 && mod(ch4) > 100 && ch4 > 0)
    {
      // RIGHT_B
      digitalWrite(t1,HIGH);
      digitalWrite(t2,LOW);
      digitalWrite(t3,LOW);
      digitalWrite(t4,LOW);
    }
    else if(mod(ch2) < 100 && mod(ch4) < 100)
    {
      digitalWrite(t1,LOW);
      digitalWrite(t2,LOW);
      digitalWrite(t3,LOW);
      digitalWrite(t4,LOW);      
    }
  }
  else if(ch3 > 100)
  {
    if(ch2 < -150 && mod(ch4) < 100)
    {
      // BACKWARD
      digitalWrite(t1,HIGH);
      digitalWrite(t2,LOW);
      digitalWrite(t3,HIGH);
      digitalWrite(t4,LOW);
    }
    else if(ch2 < -150 && mod(ch4) > 100 && ch4 < 0)
    {
      // F_LEFT
      digitalWrite(t1,HIGH);
      digitalWrite(t2,LOW);
      digitalWrite(t3,LOW);
      digitalWrite(t4,HIGH);
    }
    else if(ch2 < -150 && mod(ch4) > 100 && ch4 > 0)
    {
      // F_RIGHT
      digitalWrite(t1,LOW);
      digitalWrite(t2,HIGH);
      digitalWrite(t3,HIGH);
      digitalWrite(t4,LOW);
    }
    else if(ch4 < -150 && mod(ch2) < 100)
    {
      // RIGHT_R
      digitalWrite(t1,HIGH);
      digitalWrite(t2,LOW);
      digitalWrite(t3,LOW);
      digitalWrite(t4,LOW);
    }
    else if(ch4 > 150 && mod(ch2) < 100)
    {
      // LEFT_R
      digitalWrite(t1,LOW);
      digitalWrite(t2,LOW);
      digitalWrite(t3,HIGH);
      digitalWrite(t4,LOW);
    }   
    else if(ch2 > 150 && mod(ch4) < 100)
    {
      // FORWARD
      digitalWrite(t1,LOW);
      digitalWrite(t2,HIGH);
      digitalWrite(t3,LOW);
      digitalWrite(t4,HIGH);
    }
    else if(ch2 > 150 && mod(ch4) > 100 && ch4 < 0)
    {
      // RIGHT_B_R
      digitalWrite(t1,LOW);
      digitalWrite(t2,HIGH);
      digitalWrite(t3,LOW);
      digitalWrite(t4,LOW);
    }
    else if(ch2 > 150 && mod(ch4) > 100 && ch4 > 0)
    {
      // LEFT_B_R  
      digitalWrite(t1,LOW);
      digitalWrite(t2,LOW);
      digitalWrite(t3,LOW);
      digitalWrite(t4,HIGH);
    }
    else if(mod(ch2) < 100 && mod(ch4) < 100)
    {
      digitalWrite(t1,LOW);
      digitalWrite(t2,LOW);
      digitalWrite(t3,LOW);
      digitalWrite(t4,LOW);
    }

  }
  else {
    digitalWrite(t1,LOW);
    digitalWrite(t2,LOW);
    digitalWrite(t3,LOW);
    digitalWrite(t4,LOW);
  }

}


int mod(int n) { return n < 0? n * -1: n; }
