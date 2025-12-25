int S_A = 10;  //speed motor a
int S_B = 9;  //speed motor b
int M_A1 = 5; //motor a = +
int M_A2 = 4; //motor a = -
int M_B1 = 7; //motor b = -
int M_B2 = 8; //motor b = +

int R_S = 12; //sincer R
int S_S = 13; //sincer S
int L_S = 11; //sincer L

// Set left motor

void setup() 
{
pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
pinMode(M_A1, OUTPUT);
pinMode(M_A2, OUTPUT);
pinMode(S_B, OUTPUT);
pinMode(S_A, OUTPUT);

pinMode(L_S, INPUT);
pinMode(S_S, INPUT);
pinMode(R_S, INPUT);

analogWrite(S_A,45); //right
analogWrite(S_B, 45); 
delay(200);
}
void loop()
{  
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forword();}

if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();}
if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) ==0)&&(digitalRead(R_S) == 0)) {turnLeft();}

if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();}
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}

if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){Stop();}
}
void forword() {
  analogWrite(S_A,70); 
  analogWrite(S_B,70); 
  // Right motor: forward
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);

  // Left motor: forward
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW); 
}

void turnRight() {
  // Slow down right motor
  analogWrite(S_A, 0);          
  // Move left motor forward slowly
  analogWrite(S_B, 45);
  
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);

  // Left motor forward
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);  
}
void turnLeft() {
  // Move right motor forward slowly
  analogWrite(S_A, 45);
  // Slow left motor
  analogWrite(S_B, 0);

  
  // Right motor backward
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);

  // Left motor stop
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
}
void Stop(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}