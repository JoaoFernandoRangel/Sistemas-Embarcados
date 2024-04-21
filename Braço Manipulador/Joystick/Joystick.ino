



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A2, INPUT); // x
  pinMode(A1, INPUT); // y
  pinMode(2, INPUT_PULLUP); // botao
  pinMode(3, OUTPUT); // led
}
int inputx = 512;
int inputy = 512;
int x,y;
bool bt = 0, bounce = 1;
void loop() {
  // put your main code here, to run repeatedly:
  y = analogRead(A1);
  x = analogRead(A2);
  //bt = digitalRead(2);
  if (!digitalRead(2) and bounce == 1){
    bt = !bt;
    digitalWrite(3, bt);
    inputx = 512;
    inputy = 512;
    bounce = 0;
    delay(200);
  }else{
    bounce = 1;
  }
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(bt);
  Serial.print(" ");
  if (x>700){
    inputx += 30;
    delay(250);
  }
  if (x<200){
    inputx -= 30;
    delay(250);
  }
  if (y>700){
    inputy += 30;
    delay(250);
  }
  if (y<200){
    inputy -= 30;
    delay(250);
  }
  if (inputx > 1023){
    inputx = 1023;
  }
  if (inputx < 0){
    inputx = 0;
  }  
  if (inputy > 1023){
    inputy = 1023;
  }
  if (inputy < 0){
    inputy = 0;
  }
  Serial.print(inputx);
  Serial.print(" ");
  
  Serial.println(inputy);
  //Serial.print(" ");
}
//meio é x = 488-489
//meio é y = 516-517



