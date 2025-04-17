#include <MyButton.h>

const int GPIO_BUTTON_TO_USE = 15;
MyButton myButton(GPIO_BUTTON_TO_USE);

void setup()
{
    Serial.begin(9600);
    Serial.println(F("Exemple d'utilisation de MyButton"));
}

void loop()
{
    int buttonAction = myButton.checkMyButton();
    switch (buttonAction)
    {
    case MYBUTTON_SHORT_CLICK:
        Serial.println("Relâché (court)");
        break;
    case MYBUTTON_LONG_CLICK:
        Serial.println("Appui long");
        break;
    case MYBUTTON_DOUBLE_CLICK:
        Serial.println("Double clic");
        break;
    default:
        break;
    }
}