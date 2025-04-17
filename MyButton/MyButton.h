#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <Arduino.h>

// Define button states
#define MYBUTTON_NO_CLICK 0
#define MYBUTTON_SHORT_CLICK 2
#define MYBUTTON_LONG_CLICK 3
#define MYBUTTON_DOUBLE_CLICK 4

class MyButton
{
private:
    int buttonGPIO;
    int buttonDebounceDelay;
    int buttonLongPressDuration;
    int buttonDoubleClickMaxDelay;
    bool isPressed;
    bool lastRawState;
    unsigned long lastDebounceTime;
    unsigned long pressStart;
    unsigned long lastReleaseTime;
    bool waitingSecondClick;
    bool pendingSingleClick;

public:
    // Constructor
    MyButton(int gpioNumber, int typebouton = INPUT_PULLDOWN);

    // Setter methods
    void setButtonDebounceDelay(int delay);
    void setButtonLongPressDuration(int duration);
    void setButtonDoubleClickMaxDelay(int delay);

    int checkMyButton();
};

#endif