#include <Servo.h>

Servo serv;

//Função para ativar o motor DC
int motordc(int a);

//Função para ativar o motor Servo
int motorserv(int b);

//Variáveis constantes
const int botao = 10;
const int motorDC = 5;
const int motorServo = 7;
const int botao2 = 3;

//Variáveis vão alterar o valor
int distancia = 0;
int metro = 0;
int confirma = 0;

void setup ()
{
  pinMode(botao, INPUT);
  pinMode(botao2, INPUT);
  pinMode(motorDC, OUTPUT);
  //pinMode(motorServo, OUTPUT);
  serv.attach(motorServo);
  serv.write(0);
  Serial.begin(9600);
}

void loop()
{
  delay(2000); 
  while(confirma == 0)
  {
    delay(250);
    confirma = digitalRead(botao2);
    delay(250);
    confirma = digitalRead(botao2);
    if(confirma == 1)
    {
      delay(250);
    }
    confirma = digitalRead(botao2);   
    delay(250);
    confirma = digitalRead(botao2);
    
    //Serial.println(confirma);
  }
  delay(1000);
  Serial.println("confirmou, liga o motor servo:");
  metro++; 
  motorserv(confirma);
  confirma = 0;
  metro = 0;
}

int motordc(int a)
{
  Serial.println("Puxa a mola:");
  int tempo = a * 1000;
  delay(1000);
  digitalWrite(motorDC, HIGH);
  
  //Serial.println(digitalRead(motorDC));
  //Serial.println(tempo);
  delay(tempo);
  digitalWrite(5, LOW);
  delay(1000);
  motorserv(2);
}

int motorserv(int b)
{
  serv.write(0);
  
  //Serial.println(b);
  if(b == 1)
  {
    delay(1000);
    Serial.println("Travou:");
    serv.write(90);
    motordc(metro);   
  }
  if(b == 2)
  {
    Serial.println("Solta a haste.");
    serv.write(0);  
  }
}
