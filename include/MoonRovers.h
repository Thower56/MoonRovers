#pragma once
#include "Joystick.h"
#include "Arduino.h"

class MoonRovers{
public:
    MoonRovers(int p_MotorENA, int p_MotorENB, int p_MotorIN1, int p_MotorIN2, int p_MotorIN3, int p_MotorIN4, Joystick* p_Joystick);
    void MovingSpeed(int p_motorSpeedA, int p_motorSpeedB);
    void StopMoving();
    void MovingForward();
    void MovingBackward();
    void Moving();
    void DirectionY();
    void Differentiel();
private:
    int m_MotorENA;
    int m_MotorIN1;
    int m_MotorIN2;
    int m_MotorENB;
    int m_MotorIN3;
    int m_MotorIN4;

    int m_MotorSpeedA;
    int m_MotorSpeedB;
    Joystick* m_JoystickControl;
};