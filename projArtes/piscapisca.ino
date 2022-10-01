const int buttonPin = 1;

void setup()
{
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);

    // 2, 3, 4, 5, 6 -> group 1
    // 7, 8, 9, 10, 11 -> group 2

    // all white leds

    pinMode(1, INPUT);

    // 1 -> buttonPin

}

void loop()
{
    buttonState = digitalRead(buttonPin);

    if(buttonState == HIGH){
        pisca1();
    } else {
        digitalWrite(2, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(10, HIGH);

        digitalWrite(3, LOW);
        digitalWrite(5, LOW);
        digitalWrite(7, LOW);
        digitalWrite(9, LOW);
        digitalWrite(11, LOW);

        delay(500);

        digitalWrite(3, LOW);
        digitalWrite(5, LOW);
        digitalWrite(7, LOW);
        digitalWrite(9, LOW);
        digitalWrite(11, LOW);

        digitalWrite(2, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(10, HIGH);

        delay(500);

    }
}

void pisca1()
{
    
    buttonState = digitalRead(buttonPin);

    if(buttonState == HIGH) {
        pisca2();
    } else {
        digitalWrite(11, LOW);
        digitalWrite(2, HIGH);
        delay(1000);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        delay(1000);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        delay(1000);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        delay(1000);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        delay(1000);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        delay(1000);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        delay(1000);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        delay(1000);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        delay(1000);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        delay(1000);

    }
    
}

void pisca2()
{

    buttonState = digitalRead(buttonPin);

    if(buttonState == HIGH) {
        loop();
    } else {
        
    }
}
