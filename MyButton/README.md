# MyButton Library

## Overview

The `MyButton` library allows easy detection of button states (short click, long press, double click) on a PullDown button for Arduino projects.

## Features

- Detects short clicks, long presses, and double clicks.
- Configurable debounce delay, long press duration, and double-click timeout.

## Installation

1. Download the library folder (`MyButton`).
2. Place it in your Arduino `libraries` folder.
3. Include the library in your sketch with `#include <MyButton.h>`.

## Usage

See the example in the `examples` folder (`MyButtonExample.ino`).

### Example

```cpp
#include <MyButton.h>

const int GPIO_BUTTON_TO_USE = 15;
MyButton myButton(GPIO_BUTTON_TO_USE);

void setup() {
    Serial.begin(9600);
    Serial.println(F("Exemple d'utilisation de MyButton"));
}

void loop() {
    int buttonAction = myButton.checkMyButton();
    switch (buttonAction) {
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
```
