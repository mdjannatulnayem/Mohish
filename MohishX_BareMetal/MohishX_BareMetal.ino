// MOHISH-X ASL 2024
// MD. JANNATUL NAYEM
// NO SERIAL COMM USED
// MINIMAL FUNCTION CALL FOCUSED
// BARE METAL

#define pd2   2 // Digital 2
#define pd4   4 // Digital 4
#define pc0   0 // Analog A0
#define pc1   1 // Analog A1
#define pb0   0 // Digital 8

#define t3    pd2 // MotorA+
#define t4    pd4 // MotorA-
#define t1    pc0 // MotorB+
#define t2    pc1 // MotorB-

#define rt    pb0 // swap-relay

#define c2   11 // channel 2
#define c3   10 // channel 3
#define c4    9 // channel 4
#define c5   12 // channel 5

void setup() 
{
  // pinMode(t1,OUTPUT);
  DDRC |= 1 << pc0;
  // pinMode(t2,OUTPUT);
  DDRC |= 1 << pc1;
  // pinMode(t3,OUTPUT);
  DDRD |= 1 << pd2;
  // pinMode(t4,OUTPUT);
  DDRD |= 1 << pd4;
  // pinMode(rt,OUTPUT);
  DDRB |= 1 << pb0;

  // Serial.begin(9600);

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

  // digitalWrite(rt,ch5);
  PORTB = ch5 == 1? PORTB | 1 << pb0 : PORTB & ~(1 << pb0);

  if(ch3 < -100)
  {
    if(ch2 < -150 && mod(ch4) < 100)
    {
      // FORWARD
      // Serial.println("FORWARD");
      // digitalWrite(t1,LOW);
      PORTC &= ~(1 << pc0);
      // digitalWrite(t2,HIGH);
      PORTC |= 1 << pc1;
      // digitalWrite(t3,LOW);
      PORTD &= ~(1 << pd2);
      // digitalWrite(t4,HIGH);
      PORTD |= 1 << pd4;
    }
    else if(ch2 < -150 && mod(ch4) > 100 && ch4 < 0)
    {
      // F_LEFT
      // Serial.println("F_LEFT");
      // digitalWrite(t1,HIGH);
      PORTC |= 1 << pc0;
      // digitalWrite(t2,LOW);
      PORTC &= ~(1 << pc1);
      // digitalWrite(t3,LOW);
      PORTD &= ~(1 << pd2);
      // digitalWrite(t4,HIGH);
      PORTD |= 1 << pd4;
    }
    else if(ch2 < -150 && mod(ch4) > 100 && ch4 > 0)
    {
      // F_RIGHT
      // Serial.println("F_RIGHT");
      // digitalWrite(t1,LOW);
      PORTC &= ~(1 << pc0);
      // digitalWrite(t2,HIGH);
      PORTC |= 1 << pc1;
      // digitalWrite(t3,HIGH);
      PORTD |= 1 << pd2;
      // digitalWrite(t4,LOW);
      PORTD &= ~(1 << pd4);
    }
    else if(ch4 < -150 && mod(ch2) < 100)
    {
      // LEFT
      // Serial.println("LEFT");
      // digitalWrite(t1,LOW);
      PORTC &= ~(1 << pc0);
      // digitalWrite(t2,LOW);
      PORTC &= ~(1 << pc1);
      // digitalWrite(t3,LOW);
      PORTD &= ~(1 << pd2);
      // digitalWrite(t4,HIGH);
      PORTD |= 1 << pd4;
    }
    else if(ch4 > 150 && mod(ch2) < 100)
    {
      // RIGHT
      // Serial.println("RIGHT");
      // digitalWrite(t1,LOW);
      PORTC &= ~(1 << pc0);
      // digitalWrite(t2,HIGH);
      PORTC |= 1 << pc1;
      // digitalWrite(t3,LOW);
      PORTD &= ~(1 << pd2);
      // digitalWrite(t4,LOW);
      PORTD &= ~(1 << pd4);
    }   
    else if(ch2 > 150 && mod(ch4) < 100)
    {
      // BACKWARD
      // Serial.println("BACKWARD");
      // digitalWrite(t1,HIGH);
      PORTC |= 1 << pc0;
      // digitalWrite(t2,LOW);
      PORTC &= ~(1 << pc1);
      // digitalWrite(t3,HIGH);
      PORTD |= 1 << pd2;
      // digitalWrite(t4,LOW);
      PORTD &= ~(1 << pd4);
    }
    else if(ch2 > 150 && mod(ch4) > 100 && ch4 < 0)
    {
      // LEFT_B
      // Serial.println("LEFT_B");
      // digitalWrite(t1,LOW);
      PORTC &= ~(1 << pc0);
      // digitalWrite(t2,LOW);
      PORTC &= ~(1 << pc1);
      // digitalWrite(t3,HIGH);
      PORTD |= 1 << pd2;
      // digitalWrite(t4,LOW);
      PORTD &= ~(1 << pd4);
    }
    else if(ch2 > 150 && mod(ch4) > 100 && ch4 > 0)
    {
      // RIGHT_B
      // Serial.println("RIGHT_B");
      // digitalWrite(t1,HIGH);
      PORTC |= 1 << pc0;
      // digitalWrite(t2,LOW);
      PORTC &= ~(1 << pc1);
      // digitalWrite(t3,LOW);
      PORTD &= ~(1 << pd2);
      // digitalWrite(t4,LOW);
      PORTD &= ~(1 << pd4);
    }
    else if(mod(ch2) < 100 && mod(ch4) < 100)
    {
      // NO_MOVE
      // Serial.println("NO_MOVE");
      // digitalWrite(t1,LOW);
      PORTC &= ~(1 << pc0);
      // digitalWrite(t2,LOW);
      PORTC &= ~(1 << pc1);
      // digitalWrite(t3,LOW);
      PORTD &= ~(1 << pd2);
      // digitalWrite(t4,LOW);
      PORTD &= ~(1 << pd4);     
    }
  }
  else if(ch3 > 100)
  {
    if(ch2 < -150 && mod(ch4) < 100)
    {
      // BACKWARD
      // Serial.println("FORWARD");
      // digitalWrite(t1,HIGH);
      PORTC |= 1 << pc0;
      // digitalWrite(t2,LOW);
      PORTC &= ~(1 << pc1);
      // digitalWrite(t3,HIGH);
      PORTD |= 1 << pd2;
      // digitalWrite(t4,LOW);
      PORTD &= ~(1 << pd4);
    }
    else if(ch2 < -150 && mod(ch4) > 100 && ch4 < 0)
    {
      // F_LEFT
      // Serial.println("F_LEFT");
      // digitalWrite(t1,HIGH);
      PORTC |= 1 << pc0;
      // digitalWrite(t2,LOW);
      PORTC &= ~(1 << pc1);
      // digitalWrite(t3,LOW);
      PORTD &= ~(1 << pd2);
      // digitalWrite(t4,HIGH);
      PORTD |= 1 << pd4;
    }
    else if(ch2 < -150 && mod(ch4) > 100 && ch4 > 0)
    {
      // F_RIGHT
      // Serial.println("F_RIGHT");
      // digitalWrite(t1,LOW);
      PORTC &= ~(1 << pc0);
      // digitalWrite(t2,HIGH);
      PORTC |= 1 << pc1;
      // digitalWrite(t3,HIGH);
      PORTD |= 1 << pd2;
      // digitalWrite(t4,LOW);
      PORTD &= ~(1 << pd4);
    }
    else if(ch4 < -150 && mod(ch2) < 100)
    {
      // RIGHT_R
      // Serial.println("LEFT");
      // digitalWrite(t1,HIGH);
      PORTC |= 1 << pc0;
      // digitalWrite(t2,LOW);
      PORTC &= ~(1 << pc1);
      // digitalWrite(t3,LOW);
      PORTD &= ~(1 << pd2);
      // digitalWrite(t4,LOW);
      PORTD &= ~(1 << pd4);
    }
    else if(ch4 > 150 && mod(ch2) < 100)
    {
      // LEFT_R
      // Serial.println("RIGHT");
      // digitalWrite(t1,LOW);
      PORTC &= ~(1 << pc0);
      // digitalWrite(t2,LOW);
      PORTC &= ~(1 << pc1);
      // digitalWrite(t3,HIGH);
      PORTD |= 1 << pd2;
      // digitalWrite(t4,LOW);
      PORTD &= ~(1 << pd4);
    }   
    else if(ch2 > 150 && mod(ch4) < 100)
    {
      // FORWARD
      // Serial.println("BACKWARD");
      // digitalWrite(t1,LOW);
      PORTC &= ~(1 << pc0);
      // digitalWrite(t2,HIGH);
      PORTC |= 1 << pc1;
      // digitalWrite(t3,LOW);
      PORTD &= ~(1 << pd2);
      // digitalWrite(t4,HIGH);
      PORTD |= 1 << pd4;
    }
    else if(ch2 > 150 && mod(ch4) > 100 && ch4 < 0)
    {
      // RIGHT_B_R
      // Serial.println("LEFT_B");
      // digitalWrite(t1,LOW);
      PORTC &= ~(1 << pc0);
      // digitalWrite(t2,HIGH);
      PORTC |= 1 << pc1;
      // digitalWrite(t3,LOW);
      PORTD &= ~(1 << pd2);
      // digitalWrite(t4,LOW);
      PORTD &= ~(1 << pd4);
    }
    else if(ch2 > 150 && mod(ch4) > 100 && ch4 > 0)
    {
      // LEFT_B_R
      // Serial.println("RIGHT_B");
      // digitalWrite(t1,LOW);
      PORTC &= ~(1 << pc0);
      // digitalWrite(t2,LOW);
      PORTC &= ~(1 << pc1);
      // digitalWrite(t3,LOW);
      PORTD &= ~(1 << pd2);
      // digitalWrite(t4,HIGH);
      PORTD |= 1 << pd4;
    }
    else if(mod(ch2) < 100 && mod(ch4) < 100)
    {
      // NO_MOVE
      // Serial.println("NO_MOVE");
      // digitalWrite(t1,LOW);
      PORTC &= ~(1 << pc0);
      // digitalWrite(t2,LOW);
      PORTC &= ~(1 << pc1);
      // digitalWrite(t3,LOW);
      PORTD &= ~(1 << pd2);
      // digitalWrite(t4,LOW);
      PORTD &= ~(1 << pd4);
    }

  }
  else {
    // NO_MOVE
    // Serial.println("INVALID");
    // digitalWrite(t1,LOW);
    PORTC &= ~(1 << pc0);
    // digitalWrite(t2,LOW);
    PORTC &= ~(1 << pc1);
    // digitalWrite(t3,LOW);
    PORTD &= ~(1 << pd2);
    // digitalWrite(t4,LOW);
    PORTD &= ~(1 << pd4);
  }

}


int mod(int n) { return n < 0? n * -1: n; }
