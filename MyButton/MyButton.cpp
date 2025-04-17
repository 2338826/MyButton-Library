#include "MyButton.h"

MyButton::MyButton(int gpioNumber, int typebouton)
{
    buttonGPIO = gpioNumber;
    buttonDebounceDelay = 50;
    buttonLongPressDuration = 1000;
    buttonDoubleClickMaxDelay = 400;
    isPressed = false;
    lastRawState = false;
    lastDebounceTime = 0;
    pressStart = 0;
    lastReleaseTime = 0;
    waitingSecondClick = false;
    pendingSingleClick = false;

    // Initialize the pin
    pinMode(buttonGPIO, typebouton);
}

void MyButton::setButtonDebounceDelay(int delay)
{
    buttonDebounceDelay = delay;
}

void MyButton::setButtonLongPressDuration(int duration)
{
    buttonLongPressDuration = duration;
}

void MyButton::setButtonDoubleClickMaxDelay(int delay)
{
    buttonDoubleClickMaxDelay = delay;
}

int MyButton::checkMyButton()
{
    bool rawState = digitalRead(buttonGPIO);
    unsigned long now = millis();

    // Debounce
    if (rawState != lastRawState)
    {
        lastDebounceTime = now;
        lastRawState = rawState;
    }

    if ((now - lastDebounceTime) > buttonDebounceDelay)
    {
        if (rawState == HIGH && !isPressed)
        {
            isPressed = true;
            pressStart = now;
        }
        if (rawState == LOW && isPressed)
        {
            isPressed = false;
            unsigned long pressDuration = now - pressStart;

            if (pressDuration >= buttonLongPressDuration)
            {
                waitingSecondClick = false;
                pendingSingleClick = false;
                return MYBUTTON_LONG_CLICK; // Long press
            }
            if (waitingSecondClick)
            {
                waitingSecondClick = false;
                pendingSingleClick = false;
                return MYBUTTON_DOUBLE_CLICK; // Double click
            }
            else
            {
                waitingSecondClick = true;
                pendingSingleClick = true;
                lastReleaseTime = now;
            }
        }
    }

    // Check for single click timeout
    if (pendingSingleClick && (now - lastReleaseTime > buttonDoubleClickMaxDelay))
    {
        pendingSingleClick = false;
        waitingSecondClick = false;
        return MYBUTTON_SHORT_CLICK;
    }

    return MYBUTTON_NO_CLICK;
}