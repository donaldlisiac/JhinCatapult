#include <Servo.h>

Servo serv;

//Define estado dos botões
int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

int IN1 = 4;
int IN2 = 7;

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
  pinMode(motorServo, OUTPUT);
  serv.attach(motorServo);
  serv.write(0);
  Serial.begin(9600);
}

void loop()
{

  int reading1 = digitalRead(botao);
  int reading2 = digitalRead(botao2);

  if (reading1 != lastButtonState)
  {
    lastDebounceTime = millis();
    Serial.println("Here2");

  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {

    if (reading1 != buttonState)
    {

      buttonState = reading1;

      if (buttonState == HIGH)
      {

        metro = 4;
        motorserv(1);

      }
    }
  }

  lastButtonState = reading1;

  if (reading2 != lastButtonState)
  {
    lastDebounceTime = millis();
    Serial.println("Here2");

  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {

    if (reading2 != buttonState)
    {

      buttonState = reading2;

      if (buttonState == HIGH)
      {

        metro = 1;
        motorserv(1);

      }
    }
  }

  lastButtonState = reading2;

  metro = 0;
}

int motordc(int a, int rotaciona)
{
  
  Serial.println("Puxa a mola:");
  int tempo = a * 1000;
  delay(1000);
  
  
  Serial.println("motorservo");
  //Serial.println(digitalRead(motorDC));
  Serial.println(tempo);
  delay(tempo);
  digitalWrite(5, LOW);
  delay(1000);
  motorserv(2);
  Serial.println("motorservo fim");

  if(rotaciona == 1)
  {
      //Gira sentido horário
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      delay(tempo);
      //para o motor
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      motorserv(2);
  }
  if (rotaciona == 2)
  {
      //Gira sentido anti-horário
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      delay(tempo);
      //para o motor
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      delay(volta)
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
