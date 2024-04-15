/*
Código desenvolvido por João Fernando Rangel, Pedro Soeiro Sant'Anna e Davi Lipaus de Paula
*/

#include <PID_v1_bc.h>

int esquerda = 10, direita = 11;


double saida, output, setpoint = 90, kp = 5, ki = 1, kd = 1;

PID myPID(&saida, &output, &setpoint, kp, ki, kd, DIRECT);

int lado = 1;



void setup() {
  pinMode(A0, INPUT);         // potenciometro feedback
  pinMode(esquerda, OUTPUT);  // porta 10
  pinMode(direita, OUTPUT);   // porta 11
  pinMode(A1, INPUT);         // POTENCIOMETRO INPUT DE SETPOINT I/O
  myPID.SetMode(1);
  myPID.SetSampleTime(200);
  Serial.begin(9600);
  myPID.SetOutputLimits(-255, 255);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  setpoint = map(analogRead(A1), 80, 900, 0, 180);  // valor na planta
  //Serial.print("Potenciometro: ");
  saida = map(analogRead(A0), 20, 960, 0, 180);  // valor introduzido pelo usuário
  if (myPID.Compute()) {/*
    Serial.print(0);
    Serial.print(" ");
    Serial.print(setpoint);
    Serial.print(" ");
    Serial.print(saida);
    Serial.print(" ");
    Serial.println(200);*/
    if (output > 0) {
      analogWrite(direita, output);
      analogWrite(esquerda, 0);

    } else {
      analogWrite(esquerda, abs(output));
      analogWrite(direita, 0);
    }
  }
}
