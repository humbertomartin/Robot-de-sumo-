#include <AFMotor.h>
AF_DCMotor motor_derecho(3);   //motor derecho
AF_DCMotor motor_izquierdo(4);   //motor izquierdo
// TCS230 color recognition sensor 
// Sensor connection pins to Arduino are shown in comments

//VARIABLES DEL SENSOR ULTRA 
const int trigPin_Frente= 49; // Pin disparador. Se puede usar otro pin digital
const int echoPin _Frente= 48; // Pin eco. Se puede usar otro pin digital
const int trigPin_Atras=; // Pin disparador. Se puede usar otro pin digital
const int echoPin _Atras= ; // Pin eco. Se puede usar otro pin digital
long duration, inches, cm; // Declara variables

//VARIABLES DEL SENSOR INFRARROJO
//s1
int frente_1=31;
//s2
int atras_2=30;
//s3
int izquierda_3=32;
//s4
int derecha_4=33;

// lectura de sensores
int l1=1;
int l2=1;
int l3=1; //iquierda 
int l4=1;//derecha

//colores 
int neg=1;
int bco=0;

void setup() {
  //SENSORES INFRARROJOS 
  Serial.begin(9600);
  //s1
   pinMode(frente_1,INPUT);
   //s2
   pinMode(atras_2,INPUT);
   //s3
   pinMode(izquierda_3,INPUT);
   //s4
   pinMode(derecha_4,INPUT);

  //SENSORES ULTRA
  pinMode(trigPin_Frente, OUTPUT); // Establece pin como salida
  pinMode(echoPin_Frente, INPUT); // Establece pin como entrada
  digitalWrite(trigPin_Frente, LOW); // Pone el pin a un estado logico bajo
  
  pinMode(trigPin_Atras, OUTPUT); // Establece pin como salida
  pinMode(echoPin_Atras, INPUT); // Establece pin como entrada
  digitalWrite(trigPin_Atras, LOW); // Pone el pin a un estado logico bajo
 
  delay(5000);
}
 
  void loop() {
    
    //ultra();
   /*l1=digitalRead(frente_1);
   l2=digitalRead(atras_2);
   l3=digitalRead(izquierda_3);
   l4=digitalRead(derecha_4);    
   Serial.println("frente");
    Serial.println(l1, DEC); 
    Serial.println("atras");
    Serial.println(l2, DEC);
    Serial.println("Izquierda");
    Serial.println(l3, DEC);
    Serial.println("derecha");
    Serial.println(l4, DEC);  
    Serial.println("___________________________________________________________________________________________");
     
   delay(2000);*/
   //////////////////////////////////////////////////////////////////////////////////////////////////////
   if(l1==neg && l2==neg ){
       motor_derecho.setSpeed(10);
       motor_derecho.run(FORWARD);
       motor_izquierdo.setSpeed(250);
       motor_izquierdo.run(BACKWARD);
  }
  if (l1==bco && l2==neg){//se salio de la parte de enfrente
      motor_derecho.setSpeed(0);
      motor_derecho.run (RELEASE);
      motor_izquierdo.setSpeed(0);
      motor_izquierdo.run(RELEASE);

      motor_derecho.setSpeed(250);
      motor_derecho.run (BACKWARD);
      motor_izquierdo.setSpeed(0);
      motor_izquierdo.run(BACKWARD);
}

if (l1==neg && l2==bco){ //se salio de la parte de atras
      motor_derecho.setSpeed(0);
      motor_derecho.run (RELEASE);
      motor_izquierdo.setSpeed(0);
      motor_izquierdo.run(RELEASE);

      motor_derecho.setSpeed(250);
      motor_derecho.run (FORWARD);
      motor_izquierdo.setSpeed(0);
      motor_izquierdo.run(FORWARD);
}
if  (l3==neg && l4==bco){ //se salio de la izquierda deve girar a la derecha
    
      motor_derecho.setSpeed(0);
      motor_derecho.run (FORWARD);
      motor_izquierdo.setSpeed(0);
      motor_izquierdo.run(FORWARD);
}
if (l3==bco && l4==neg){ // se salio de la derecha deve girar a la izquierda
  

      motor_derecho.setSpeed(250);
      motor_derecho.run (FORWARD);
      motor_izquierdo.setSpeed(0);
      motor_izquierdo.run(FORWARD);
}
  
}
// Calcula la distancia en pulgadas
long microsecondsToInches(long microseconds) {
     return microseconds/148;
}
// Calcula la distancia en cm
long microsecondsToCentimeters(long microseconds) {
     return microseconds/58;
}
void ultra(){
     // lectura ultrasonico
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH); //Devuelve la longitud del pulso del pin Echo en us
   // Imprime valores por el puerto serie:
   // Convierte el tiempo de recepción del eco en distancia:
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   //Serial.println(cm);
} 
