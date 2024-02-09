#include <Arduino.h>
#include "MoonRovers.h"
#include "Joystick.h"

MoonRovers* rover;

void setup() {
  rover = new MoonRovers(3,9,5,6,10,11, new Joystick(34,35,9));
}

void loop() {
  
}

