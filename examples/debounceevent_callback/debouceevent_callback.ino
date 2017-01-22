/*

  Debounce buttons and trigger events
  Copyright (C) 2015-2017 by Xose Pérez <xose dot perez at gmail dot com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <DebounceEvent.h>

#define BUTTON_UP       0
#define BUTTON_DOWN     4

void callback(uint8_t pin, uint8_t event) {

    if (pin == BUTTON_UP) {
        Serial.print("Button UP: ");
    } else {
        Serial.print("Button DOWN: ");
    }

    if (event == EVENT_CHANGED) Serial.println("Changed");
    if (event == EVENT_PRESSED) Serial.println("Pressed");
    if (event == EVENT_SINGLE_CLICK) Serial.println("Click");
    if (event == EVENT_DOUBLE_CLICK) Serial.println("Double Click");
    if (event == EVENT_LONG_CLICK) Serial.println("Long Click");
}

DebounceEvent button1 = DebounceEvent(BUTTON_UP, callback, BUTTON_PUSHBUTTON | BUTTON_DEFAULT_HIGH);
DebounceEvent button2 = DebounceEvent(BUTTON_DOWN, callback, BUTTON_SWITCH | BUTTON_DEFAULT_HIGH | BUTTON_SET_PULLUP);

void setup() {
    Serial.begin(115200);
}

void loop() {
    button1.loop();
    button2.loop();
}