#include <PID_v1_bc.h>
// Definir limites de segurança


struct Motor{
  uint8_t retorno;
  int aumentar; // definimos 1 como aumentar o angulo com relação à mesa
  int diminuir; // definimos 2 como diminuir o angulo com relação à mesa
};

struct Motor motor1 = {
  .retorno = 'A0',
  .aumentar = 4,
  .diminuir = 5
};

struct Motor motor2 = {
  .retorno = 'A1',
  .aumentar = 6,
  .diminuir = 7
};

struct Motor motor3 = {
  .retorno = 'A2',
  .aumentar = 8,
  .diminuir = 9
};

struct Motor motor4 = {
  .retorno = 'A3',
  .aumentar = 10,
  .diminuir = 11
};

/*************Declarações das variáveis dos PID's******/
double input1,output1,retorno1, kp1=1, ki1=1, kd1=1;
double input2,output2,retorno2, kp2=1, ki2=1, kd2=1;
double input3,output3,retorno3, kp3=1, ki3=1, kd3=1;
double input4,output4,retorno4, kp4=1, ki4=1, kd4=1;
/*************Declarações de PID****************/
PID pid_motor1(&input1, &output1, &retorno1, kp1, ki1, kd1, DIRECT);
PID pid_motor2(&input2, &output2, &retorno2, kp2, ki2, kd2, DIRECT);
PID pid_motor3(&input3, &output3, &retorno3, kp3, ki3, kd3, DIRECT);
PID pid_motor4(&input4, &output4, &retorno4, kp4, ki4, kd4, DIRECT);
/**********************************************/
void setup() {
  //*********Declaração das entradas do retorno******/  
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

void loop() {
   /*Adicionar função seletora de pose a partir de um input de comunicação serial.
   A função deve pegar os valores da comunicação serial e atribuir cada um deles para um input*/
  



  if(pid_motor1.Compute()){
    if(ouput1 > 0){ // aumentar o angulo
      analogWrite(motor1.aumentar, output1);
      analogWrite(motor1.diminuir, 0);
    } else{ // diminuir o angulo
      analogWrite(motor1.aumentar, 0);
      analogWrite(motor1.diminuir, abs(output1));
    }
  }
    if(pid_motor2.Compute()){
    if(ouput1 > 0){ // aumentar o angulo
      analogWrite(motor2.aumentar, output1);
      analogWrite(motor2.diminuir, 0);
    } else{ // diminuir o angulo
      analogWrite(motor2.aumentar, 0);
      analogWrite(motor2.diminuir, abs(output1));
    }
  }  if(pid_motor3.Compute()){
    if(ouput1 > 0){ // aumentar o angulo
      analogWrite(motor3.aumentar, output1);
      analogWrite(motor3.diminuir, 0);
    } else{ // diminuir o angulo
      analogWrite(motor3.aumentar, 0);
      analogWrite(motor3.diminuir, abs(output1));
    }
  }  if(pid_motor4.Compute()){
    if(ouput1 > 0){ // aumentar o angulo
      analogWrite(motor4.aumentar, output1);
      analogWrite(motor4.diminuir, 0);
    } else{ // diminuir o angulo
      analogWrite(motor4.aumentar, 0);
      analogWrite(motor4.diminuir, abs(output1));
    }
  }









}
