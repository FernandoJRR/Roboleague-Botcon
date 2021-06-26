#include <SoftwareSerial.h>

//Inicializar BT
SoftwareSerial BT1(0,1);

char Incoming_value=0;

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
int Pin_Velocidad_Der = 10;

void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);

    //encender key
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  //Se configura BT
  Serial.println("Enter AT commands:");
  BT1.begin(38400); // HC-05 default speed in AT command more
  
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
  if (BT1.available()) // read from HC-05 and send to Arduino Serial Monitor
      Serial.write(BT1.read());
    
  if (Serial.available()){ // Keep reading from Arduino Serial Monitor and send to HC-05
    BT1.write(Serial.read());
  }

  //movemos el robot hacia delante por 2 segundos
char dato=Serial.read();
if(dato=='w')
     {
        Serial.write(dato);
        Mover_Adelante();
     
     }
     else if(dato=='/'){
        Mover_Stop();
     }
}
void Mover_Adelante()
{
  Serial.write("Entra");
    analogWrite(Pin_Velocidad_Der, 65);

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
