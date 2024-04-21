#include <PID_v1_bc.h>
// Definir limites de segurança

/*
int pose1[] = {325, 522, 294, 512};
int pose2[] = {560, 530, 315, 550};
int pose3[] = {422, 517, 254, 565};
*/
int pose1[] = {225, 560, 282, 542};
int pose2[] = {500, 560, 282, 542};
/*int pose2[] = {231, 500, 254, 600};
int pose3[] = {422, 517, 254, 565};*/




struct Motor{
  uint8_t retorno;
  int aumentar; // definimos 1 como aumentar o angulo com relação à mesa
  int diminuir; // definimos 2 como diminuir o angulo com relação à mesa
};

struct Motor motor1 = {
  .retorno = A0,
  .aumentar = 4,
  .diminuir = 5
};

struct Motor motor2 = {
  .retorno = A1,
  .aumentar = 6,
  .diminuir = 7
};

struct Motor motor3 = {
  .retorno = A2,
  .aumentar = 8,
  .diminuir = 9
};

struct Motor motor4 = {
  .retorno = A3,
  .aumentar = 10,
  .diminuir = 11
};

/*************Declarações das variáveis dos PID's******/
double input1,output1,retorno1, kp1=5, ki1=0.1, kd1=0;
double input2,output2,retorno2, kp2=5, ki2=0.1, kd2=0;
double input3,output3,retorno3, kp3=5, ki3=0.1, kd3=0;
double input4,output4,retorno4, kp4=5, ki4=0.1, kd4=0;

/*************Declarações de PID****************/
PID pid_motor1(&input1, &output1, &retorno1, kp1, ki1, kd1, DIRECT);
PID pid_motor2(&input2, &output2, &retorno2, kp2, ki2, kd2, DIRECT);
PID pid_motor3(&input3, &output3, &retorno3, kp3, ki3, kd3, DIRECT);
PID pid_motor4(&input4, &output4, &retorno4, kp4, ki4, kd4, DIRECT);
/**********************************************/
bool flag = 0;
void le_limites(double valor1, double valor2, double valor3, double valor4){
  if ((valor1 < 230) || (valor1 > 714)){
    flag = 1;
    Serial.print("valor1 ");
    Serial.println(flag);
  } else{
    flag = 0;
    Serial.println(flag);
  }
  if (((valor2 > 630) || (valor2 < 450)) && (valor3 >= 190)){
    flag = 1;    
    Serial.print("if2 ");
    Serial.println(flag);
  } else{
    flag = 0;
  }
  if ((valor4 < 280) && ( valor4 > 500)){
    flag = 1;
    
    Serial.print("if3 ");
    Serial.println(flag);
  } else{
    flag = 0;
  }
}
/*
void le_serial(){
  String receivedString = Serial.readStringUntil('\n');
  Serial.println(receivedString);    
  if (receivedString[4] == "1"){
    input1 = pose1[0];
    input2 = pose1[1];
    input3 = pose1[2];
    input4 = pose1[3];
  } else if (receivedString[4] == "2"){
    input1 = pose2[0];
    input2 = pose2[1];
    input3 = pose2[2];
    input4 = pose2[3];
  } else if (receivedString[4] == "3"){
    input1 = pose3[0];
    input2 = pose3[1];
    input3 = pose3[2];
    input4 = pose3[3];
  }
}
*/

void setup() {
  //*********Declaração das entradas do retorno******/ 
  Serial.begin(9600); 
  pinMode(motor1.retorno, INPUT);
  pinMode(motor2.retorno, INPUT);
  pinMode(motor3.retorno, INPUT);
  pinMode(motor4.retorno, INPUT);
  //*********Declaração das saidas dos motores******/  
  pinMode(motor1.aumentar, OUTPUT);
  pinMode(motor1.diminuir, OUTPUT);
  pinMode(motor2.aumentar, OUTPUT);
  pinMode(motor2.diminuir, OUTPUT);
  pinMode(motor3.aumentar, OUTPUT);
  pinMode(motor3.diminuir, OUTPUT);
  pinMode(motor4.aumentar, OUTPUT);
  pinMode(motor4.diminuir, OUTPUT);
  //*********Declarações PID************************/
  pid_motor1.SetMode(1);
  pid_motor1.SetSampleTime(200);
  pid_motor1.SetOutputLimits(-255, 255);
  pid_motor2.SetMode(1);
  pid_motor2.SetSampleTime(200);
  pid_motor2.SetOutputLimits(-255, 255);
  pid_motor3.SetMode(1);
  pid_motor3.SetSampleTime(200);
  pid_motor3.SetOutputLimits(-255, 255);
  pid_motor4.SetMode(1);
  pid_motor4.SetSampleTime(200);
  pid_motor4.SetOutputLimits(-255, 255);
}
bool teste = 1;
int count=0;
void loop() {
  if (teste == 1){
    if (count==10){
    input1 = pose1[0];
    input2 = pose1[1];
    input3 = pose1[2];
    input4 = pose1[3];
    } else{
    input1 = pose2[0];
    input2 = pose2[1];
    input3 = pose2[2];
    input4 = pose2[3];
    }
    retorno1 = analogRead(motor1.retorno);
    retorno2 = analogRead(motor2.retorno);
    retorno3 = analogRead(motor3.retorno);
    retorno4 = analogRead(motor4.retorno);  
    if(pid_motor1.Compute()){
    if(output1 > 0){ // aumentar o angulo
      analogWrite(motor1.aumentar, output1);
      analogWrite(motor1.diminuir, 0);
    } else{ // diminuir o angulo
      analogWrite(motor1.aumentar, 0);
      analogWrite(motor1.diminuir, abs(output1));
    }     
    Serial.print(analogRead(motor1.retorno));
    Serial.print("||");
    Serial.print(analogRead(motor2.retorno));
    Serial.print("||");
    Serial.print(analogRead(motor3.retorno));
    Serial.print("||");
    Serial.print(analogRead(motor4.retorno));
    Serial.println("||");
    count+=1;
    //le_serial();
  }/*else{
    Serial.print(analogRead(motor1.retorno));
    Serial.print("||");
    Serial.print(analogRead(motor2.retorno));
    Serial.print("||");
    Serial.print(analogRead(motor3.retorno));
    Serial.print("||");
    Serial.print(analogRead(motor4.retorno));
    Serial.println("||");
  le_limites(analogRead(motor1.retorno),analogRead(motor2.retorno),analogRead(motor3.retorno),analogRead(motor4.retorno));
  //le_serial();
  String receivedString = Serial.readStringUntil('\n');  
  String string_para_input;
  if (receivedString[0] == "p"){
    string_para_input = receivedString;
  }
  Serial.println(string_para_input);
  if (string_para_input[4] == "1"){
    input1 = pose1[0];
    input2 = pose1[1];
    input3 = pose1[2];
    input4 = pose1[3];
  } else if (string_para_input[4] == "2"){
    input1 = pose2[0];
    input2 = pose2[1];
    input3 = pose2[2];
    input4 = pose2[3];
  } else if (string_para_input[4] == "3"){
    input1 = pose3[0];
    input2 = pose3[1];
    input3 = pose3[2];
    input4 = pose3[3];
  }
  while (flag == 1){
    Serial.println("ERRO__ERRO__ERRO__GARRA FORA DOS LIMITES");
    Serial.println("-------------------------------------------");
    analogWrite(motor1.aumentar, 0);
    analogWrite(motor1.diminuir, 0);
    analogWrite(motor2.aumentar, 0);
    analogWrite(motor2.diminuir, 0);
    analogWrite(motor3.aumentar, 0);
    analogWrite(motor3.diminuir, 0);
    analogWrite(motor4.aumentar, 0);
    analogWrite(motor4.diminuir, 0);
  }
  if(pid_motor1.Compute()){
    if(output1 > 0){ // aumentar o angulo
      analogWrite(motor1.aumentar, output1);
      analogWrite(motor1.diminuir, 0);
    } else{ // diminuir o angulo
      analogWrite(motor1.aumentar, 0);
      analogWrite(motor1.diminuir, abs(output1));
    }
  }/*
  if(pid_motor2.Compute()){
    if(output1 > 0){ // aumentar o angulo
      analogWrite(motor2.aumentar, output1);
      analogWrite(motor2.diminuir, 0);
    } else{ // diminuir o angulo
      analogWrite(motor2.aumentar, 0);
      analogWrite(motor2.diminuir, abs(output1));
    }
  }  
  if(pid_motor3.Compute()){
    if(output1 > 0){ // aumentar o angulo
      analogWrite(motor3.aumentar, output1);
      analogWrite(motor3.diminuir, 0);
    } else{ // diminuir o angulo
      analogWrite(motor3.aumentar, 0);
      analogWrite(motor3.diminuir, abs(output1));
    }
  }  
  if(pid_motor4.Compute()){
    if(output1 > 0){ // aumentar o angulo
      analogWrite(motor4.aumentar, output1);
      analogWrite(motor4.diminuir, 0);
    } else{ // diminuir o angulo
      analogWrite(motor4.aumentar, 0);
      analogWrite(motor4.diminuir, abs(output1));
    }*/
  }
}

