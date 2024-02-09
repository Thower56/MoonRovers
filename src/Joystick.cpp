#include "Joystick.h"

Joystick::Joystick(int p_PinAxisY, int p_PinAxisX, int p_PinButton):
m_PinAxisX(p_PinAxisX), m_PinAxisY(p_PinAxisY), m_PinButton(p_PinButton)
{
    pinMode(m_PinAxisX, INPUT);
    pinMode(m_PinAxisY, INPUT);
    pinMode(m_PinButton, INPUT);
};

Joystick::Joystick(Joystick &p_Joystick){
    m_PinAxisX = p_Joystick.m_PinAxisX;
    m_PinAxisY = p_Joystick.m_PinAxisY;
    m_PinButton = p_Joystick.m_PinButton;
};

int Joystick::getAxisY(){
    return analogRead(m_PinAxisY) - 512;
};

int Joystick::getAxisX(){
    return analogRead(m_PinAxisX) - 512;
};

int Joystick::getButtonState(){
    return digitalRead(m_PinButton);
};