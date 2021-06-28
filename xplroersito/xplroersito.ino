#include <SoftwareSerial.h>

//Inicializar BT
SoftwareSerial BT1(10,11);

//Comando Recibido
char comando=0;

//Derecho Delantero Adelante
int Pin_Motor_Der_A = 6;
//Derecho Delantero Atras
int Pin_Motor_Der_B = 7;
//Izquierdo Delantero Adelante
int Pin_Motor_Izq_A = 8;
//Izquierdo Delantero Atras
int Pin_Motor_Izq_B = 9;

//Izquierdo Trasero Adelante
int Pin_Motor_DerAt_A = 2;
//Izquierdo Trasero Atras
int Pin_Motor_DerAt_B = 3;
//Derecho Trasero Adelante
int Pin_Motor_IzqAt_A = 4;
//Derecho Trasero Atras
int Pin_Motor_IzqAt_B = 5;

//Derecho Delantero Velocidad
int Pin_Velocidad_Der = 12;

void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);

  //Se configura BT
  BT1.begin(9600); // Iniciamos en 9600 Baudios
  
  //Se configuran motores
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Motor_Izq_A, OUTPUT);
  pinMode(Pin_Motor_Izq_B, OUTPUT);
  
  pinMode(Pin_Motor_DerAt_A, OUTPUT);
  pinMode(Pin_Motor_DerAt_B, OUTPUT);
  pinMode(Pin_Motor_IzqAt_A, OUTPUT);
  pinMode(Pin_Motor_IzqAt_B, OUTPUT);
  
  pinMode(Pin_Velocidad_Der, OUTPUT);


}

void loop() {
  comando=BT1.read();
  //Dependiendo del comando ingresado se iniciara o parara al robot
  if(comando=='w'){
    Serial.write(comando);
    Mover_Adelante(); 
  }else if(comando=='/'){
    Serial.write(comando);
    Mover_Stop();
  }
  if(Serial.available()>0){
    Serial.write(comando);
  }
}
void Mover_Adelante(){
  analogWrite(Pin_Velocidad_Der, 128);
  
  digitalWrite(Pin_Motor_Der_A, HIGH);
  digitalWrite(Pin_Motor_Der_B, LOW);
  digitalWrite(Pin_Motor_Izq_A, LOW);
  digitalWrite(Pin_Motor_Izq_B, HIGH);
  
  digitalWrite(Pin_Motor_DerAt_A, LOW);
  digitalWrite(Pin_Motor_DerAt_B, HIGH);
  digitalWrite(Pin_Motor_IzqAt_A, LOW);
  digitalWrite(Pin_Motor_IzqAt_B, HIGH);

}
void Mover_Stop()
{
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, LOW);
  digitalWrite (Pin_Motor_Izq_B, LOW);

  digitalWrite (Pin_Motor_DerAt_A, LOW);
  digitalWrite (Pin_Motor_DerAt_B, LOW);
  digitalWrite (Pin_Motor_IzqAt_A, LOW);
  digitalWrite (Pin_Motor_IzqAt_B, LOW);
}
