#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

const int buttonPin = 52;
int buttonState { 0 };
int buttonPress { 0 };

void setup()
{
    lcd.begin(16, 2);
    pinMode(buttonPin, INPUT);

    lcd.print("Waiting Input");
}

void loop()
{
    buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH)
    {
        buttonPress++;
        lcd.clear();
        lcd.print("Button Press: ");
        lcd.print(buttonPress);

        delay(1000);

        lcd.clear();
        lcd.print("Waiting Input");
    }
}