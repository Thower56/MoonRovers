#pragma once
#include "Arduino.h"

class Joystick{
public:
    Joystick(int p_PinAxisY, int p_PinAxisX, int p_PinButton);
    Joystick(Joystick &p_Joystick);
    int getAxisY();
    int getAxisX();
    int getButtonState();
private:
    int m_PinAxisY;
    int m_PinAxisX;
    int m_PinButton;
};