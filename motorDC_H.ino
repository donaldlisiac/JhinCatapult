int IN1 = 4;
int IN2 = 5;

void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
}

void loop()
{
    //Gira sentido horário
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    delay(2000);

    //Para o motor
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    delay(2000);

    //Gira sentido anti-horário
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(2000);
}