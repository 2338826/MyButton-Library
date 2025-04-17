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
    int buttonGPIO;                 // GPIO pin for the button
    int buttonDebounceDelay;        // Debounce delay in ms
    int buttonLongPressDuration;    // Long press duration in ms
    int buttonDoubleClickMaxDelay;  // Max delay for double click in ms
    bool isPressed;                 // Button pressed state
    bool lastRawState;              // Last raw state of the button
    unsigned long lastDebounceTime; // Last debounce time
    unsigned long pressStart;       // Time when press started
    unsigned long lastReleaseTime;  // Time of last release
    bool waitingSecondClick;        // Waiting for a second click
    bool pendingSingleClick;        // Pending single click detection

public:
    // Constructor
    MyButton(int gpioNumber, int typebouton = INPUT_PULLDOWN);

    // Setter methods
    void setButtonDebounceDelay(int delay);
    void setButtonLongPressDuration(int duration);
    void setButtonDoubleClickMaxDelay(int delay);

    // Method to check button state
    int checkMyButton();
};

#endif