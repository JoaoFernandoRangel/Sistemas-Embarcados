#include <PID_v1_bc.h>
// Definir limites de segurança

int pose1[] = {225, 560, 282, 542};


struct Motor{
  uint8_t retorno;
  int direita; // definimos 1 como direita o angulo com relação à mesa
  int esquerda; // definimos 2 como esquerda o angulo com relação à mesa
};

struct Motor motor1 = {
  .retorno = A0,
  .direita  = 4,
  .esquerda = 5
};



/*************Declarações das variáveis dos PID's******/
double input1,output1,retorno1, kp1=5, ki1=0.1, kd1=0;

/*************Declarações de PID****************/
PID pid_motor1(&input1, &output1, &retorno1, kp1, ki1, kd1, DIRECT);
/**********************************************/

pose[] = {230,600};
void setup() {
  //*********Declaração das entradas do retorno******/ 
  Serial.begin(9600); 
  pinMode(motor1.retorno, INPUT);
  //*********Declaração das saidas dos motores******/  
  pinMode(motor1.direita, OUTPUT);
  pinMode(motor1.esquerda, OUTPUT);
  
  //*********Declarações PID************************/
  pid_motor1.SetMode(1);
  pid_motor1.SetSampleTime(200);
  pid_motor1.SetOutputLimits(-255, 255);
  }
bool teste = 1;
int count=0;
void loop() {
  retorno1 = analogRead(motor1.retorno);
  String receivedString = Serial.readStringUntil('\n');
  if (receivedString[4] == "0"){
    input = pose[0];
  } else if (receivedString[4] == "1"){
    input = pose[1];
  }
    if(pid_motor1.Compute()){
    if(output1 > 0){ // direita o angulo
    analogWrite(motor1.direita, output1);
    analogWrite(motor1.esquerda, 0);
    } else{ // esquerda o angulo
    analogWrite(motor1.direita, 0);
    analogWrite(motor1.esquerda, abs(output1));
    }     
  Serial.print(analogRead(motor1.retorno));
}

