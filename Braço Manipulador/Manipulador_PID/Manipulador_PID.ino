#include <PID_v1_bc.h>
// Definir limites de segurança
//RD5 NT modelo Robo DItacta Italia
//int pose1[] = {225, 560, 282, 542};


struct Motor{
  uint8_t retorno;
  int direita; // definimos 1 como direita o angulo com relação à mesa
  int esquerda;
 // definimos 2 como esquerda o angulo com relação à mesa
};

struct Motor motor1 = {
  .retorno = A0,
  .direita  = 5,
  .esquerda = 4
};

struct Motor motor2 = {
  .retorno = A1,
  .direita = 6,
  .esquerda = 7
};

struct Motor motor3 = {
  .retorno = A2,
  .direita = 8,
  .esquerda = 9
};
struct Motor motor4 = {
  .retorno = A3,
  .direita = 10,
  .esquerda = 11
};

/*************Declarações das variáveis dos PID's******/
double input1 = 450,output1,retorno1, kp1=3, ki1=0.5, kd1=0;
double input2 = 546,output2,retorno2, kp2=3, ki2=0.5, kd2=0;
double input3 = 270,output3,retorno3, kp3=3, ki3=0.5, kd3=0;
double input4 = 470,output4,retorno4, kp4=3, ki4=0.5, kd4=0;

/*************Declarações de PID****************/
PID pid_motor1(&input1, &output1, &retorno1, kp1, ki1, kd1, DIRECT);
PID pid_motor2(&input2, &output2, &retorno2, kp2, ki2, kd2, DIRECT);
PID pid_motor3(&input3, &output3, &retorno3, kp3, ki3, kd3, DIRECT);
PID pid_motor4(&input4, &output4, &retorno4, kp4, ki4, kd4, DIRECT);

/**********************************************/
double pose1[] = {450, 546, 270, 470}; //Central
double pose2[] = {584, 498, 113, 484}; //Davi
double pose3[] = {312, 515, 215, 480}; //Soeiro
double pose4[] = {168, 451, 378, 380}; //Pose4
double pose5[] = {720, 489, 345, 500}; //Pose5

void setup() {
  //*********Declaração das entradas do retorno******/ 
  Serial.begin(115200); 
  pinMode(motor1.retorno, INPUT);
  pinMode(motor2.retorno, INPUT);
  pinMode(motor3.retorno, INPUT);
  pinMode(motor4.retorno, INPUT);

//*********Declaração das saidas dos motores******/  
  pinMode(motor1.direita, OUTPUT);
  pinMode(motor1.esquerda, OUTPUT);
  pinMode(motor2.direita, OUTPUT);
  pinMode(motor2.esquerda, OUTPUT);
  pinMode(motor3.direita, OUTPUT);
  pinMode(motor3.esquerda, OUTPUT);
  pinMode(motor4.direita, OUTPUT);
  pinMode(motor4.esquerda, OUTPUT); 
//*********Declarações PID************************/

  pid_motor1.SetMode(1);
  pid_motor1.SetSampleTime(100);
  pid_motor1.SetOutputLimits(-255, 255);
  pid_motor2.SetMode(1);
  pid_motor2.SetSampleTime(100);
  pid_motor2.SetOutputLimits(-255, 255);
  pid_motor3.SetMode(1);
  pid_motor3.SetSampleTime(100);
  pid_motor3.SetOutputLimits(-255, 255);
  pid_motor4.SetMode(1);
  pid_motor4.SetSampleTime(100);
  pid_motor4.SetOutputLimits(-255, 255);
}
bool teste = 1;
int count=0, i = 0;
unsigned long agora = 0;

void troca_pose(String variavel){
  switch (variavel[4]){
    case '1':
      input1 = pose1[0];
      input2 = pose1[1];
      input3 = pose1[2];
      input4 = pose1[3];
      Serial.println("pose 1");
      break;
    case '2':
      input1 = pose2[0];
      input2 = pose2[1];
      input3 = pose2[2];
      input4 = pose2[3];
      Serial.println("pose 2");
      break;
    case '3':
      input1 = pose3[0];
      input2 = pose3[1];
      input3 = pose3[2];
      input4 = pose3[3];
      Serial.println("pose 3");
      break;
    case '4':
      input1 = pose4[0];
      input2 = pose4[1];
      input3 = pose4[2];
      input4 = pose4[3];
      Serial.println("pose 4");
      break;
    case '5':
      input1 = pose5[0];
      input2 = pose5[1];
      input3 = pose5[2];
      input4 = pose5[3];
      Serial.println("pose 5");
      break;
  }
}



void loop() {  
  retorno4 = analogRead(motor4.retorno);
  retorno3 = analogRead(motor3.retorno);
  retorno2 = analogRead(motor2.retorno);
  retorno1 = analogRead(motor1.retorno);
  unsigned long tempo = millis();
  //Serial.println(tempo);
  if (Serial.available() > 4){
    String receivedString = Serial.readStringUntil('-');
    troca_pose(receivedString);  
  }

  /*
  Serial.print(retorno1);
  Serial.print("||");
  Serial.print(retorno2);
  Serial.print("||");
  Serial.print(retorno3);
  Serial.print("||");
  Serial.println(retorno4);*/

/* 
  Serial.print(analogRead(motor2.retorno));
  Serial.println(" retorno2||");
*/
  
  if(pid_motor1.Compute()){
    if(output1 > 0){ // direita o angulo
    analogWrite(motor1.direita, output1);
    analogWrite(motor1.esquerda, 0);
    } else{ // esquerda o angulo
    analogWrite(motor1.direita, 0);
    analogWrite(motor1.esquerda, abs(output1));
    }     
  }
  if(pid_motor2.Compute()){
    if(output2 > 0){ // direita o angulo
    analogWrite(motor2.direita, output2);
    analogWrite(motor2.esquerda, 0);
    } else{ // esquerda o angulo
    analogWrite(motor2.direita, 0);
    analogWrite(motor2.esquerda, abs(output2));
    }     
  }
  if(pid_motor3.Compute()){
    if(output3 > 0){ // direita o angulo
    analogWrite(motor3.direita, output3);
    analogWrite(motor3.esquerda, 0);
    } else{ // esquerda o angulo
    analogWrite(motor3.direita, 0);
    analogWrite(motor3.esquerda, abs(output3));
    }     
  }
  if(pid_motor4.Compute()){
    if(output4 > 0){ // direita o angulo
    analogWrite(motor4.direita, output4);
    analogWrite(motor4.esquerda, 0);
    } else{ // esquerda o angulo
    analogWrite(motor4.direita, 0);
    analogWrite(motor4.esquerda, abs(output4));}
  }
  //Serial.println("loop");
}

