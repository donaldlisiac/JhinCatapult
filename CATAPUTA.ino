#include <Servo.h>

Servo serv;

//Define estado dos botões
int buttonState1;
int buttonState2;
int lastButtonState1 = LOW;
int lastButtonState2 = LOW;

unsigned long lastDebounceTime1 = 0;
unsigned long debounceDelay1 = 50;
unsigned long lastDebounceTime2 = 0;
unsigned long debounceDelay2 = 50;

//Função para ativar o motor DC
int motordc(int a, int rotaciona);

//Função para ativar o motor Servo
int motorserv(int b);

//Variáveis constantes
int IN1 = 13;
int IN2 = 12;
const int botao2 = 11;
const int botao = 10;
const int motorDC = 5;
const int motorServo = 7;


//Variáveis vão alterar o valor
int distancia = 0;
int metro = 0;
int confirma = 0;

void setup ()
{
  pinMode(botao, INPUT);
  pinMode(botao2, INPUT);
  pinMode(motorDC, OUTPUT);
  pinMode(motorServo, OUTPUT);
  serv.attach(motorServo);
  serv.write(0);
  Serial.begin(9600);
}

void loop()
{

  int reading1 = digitalRead(botao);
  int reading2 = digitalRead(botao2);

  if (reading1 != lastButtonState1)
  {
    delay(125);
    lastDebounceTime1 = millis();
    Serial.println("Here1");
  }
  
   if (reading2 != lastButtonState2)
  {
    delay(125);
    lastDebounceTime2 = millis();
    Serial.println("Here2");
  }
  
  if ((millis() - lastDebounceTime1) > debounceDelay1)
  {
    if (reading1 != buttonState1)
    {
      buttonState1 = reading1;
      if (buttonState1 == HIGH)
      {
        metro = 4;
        motorserv(1);
        Serial.println("reading1");
      }
    }
  }
  lastButtonState1 = reading1;
 
  if ((millis() - lastDebounceTime2) > debounceDelay2)
  {
    if (reading2 != buttonState2)
    {
      buttonState2 = reading2;
      if (buttonState2 == HIGH)
      {
        metro = 1;
        motorserv(1);
        Serial.println("reading2");
      }
    }
  }

  lastButtonState2 = reading2;

  metro = 0;
}

int motordc(int a, int rotaciona)
{
  
  
  int tempo = a * 1000;
  delay(1000);

  if(rotaciona == 1)
  {
      Serial.println("Puxa a mola:");
      //Gira sentido horário
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      delay(tempo);
      //para o motor
      Serial.println("Para o motor:");
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      delay(2500);
      motorserv(2);      
  }
  if (rotaciona == 2)
  {
      Serial.println("Solta a mola:");
      //Gira sentido anti-horário
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      delay(tempo);
      //para o motor
      Serial.println("Para o motor:");
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      delay(2500);
  }
}

int motorserv(int b)
{  
  serv.write(0);

  //Serial.println(b);
  if (b == 1)
  {
    //trava a alavanca
    delay(1000);
    Serial.println("Travou:");
    serv.write(-20);
    motordc(metro, 1);
    
  }
  if (b == 2)
  {   
    delay(1000);
    serv.write(20);
    delay(5000);
    motordc(metro, 2);
    
  }
}
