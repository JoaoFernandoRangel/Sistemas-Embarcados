#include <PID_v1_bc.h>
// Definir limites de segurança


struct Motor{
  uint8_t retorno;
  int saida1; // definimos 1 como aumentar o angulo com relação à mesa
  int saida2; // definimos 2 como diminuir o angulo com relação à mesa
};

struct Motor motor1 = {
  .retorno = 'A0',
  .saida1 = 4,
  .saida2 = 5
};

struct Motor motor2 = {
  .retorno = 'A1',
  .saida1 = 6,
  .saida2 = 7
};

struct Motor motor3 = {
  .retorno = 'A2',
  .saida1 = 8,
  .saida2 = 9
};

struct Motor motor4 = {
  .retorno = 'A3',
  .saida1 = 10,
  .saida2 = 11
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
  pinMode(motor1.saida1, OUTPUT);
  pinMode(motor1.saida2, OUTPUT);
  pinMode(motor2.saida1, OUTPUT);
  pinMode(motor2.saida2, OUTPUT);
  pinMode(motor3.saida1, OUTPUT);
  pinMode(motor3.saida2, OUTPUT);
  pinMode(motor4.saida1, OUTPUT);
  pinMode(motor4.saida2, OUTPUT);
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
  if(pid_motor1.Compute()){
    if(ouput1 > 0){ // aumentar o angulo
      analogWrite(motor1.saida1, output1);
      analogWrite(motor1.saida2, 0);
    } else{ // diminuir o angulo
      analogWrite(motor1.saida1, 0);
      analogWrite(motor1.saida2, abs(output1));
    }
  }









}
