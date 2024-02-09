#include "MoonRovers.h"

MoonRovers::MoonRovers(int p_MotorENA, int p_MotorENB, int p_MotorIN1, int p_MotorIN2, int p_MotorIN3, int p_MotorIN4, Joystick* p_Joystick)
: m_MotorENA(p_MotorENA), m_MotorENB(p_MotorENB), m_MotorIN1(p_MotorIN1),m_MotorIN2(p_MotorIN2),m_MotorIN3(p_MotorIN3),m_MotorIN4(p_MotorIN4)
{
     m_JoystickControl = p_Joystick;
     pinMode(m_MotorENA, OUTPUT);
     pinMode(m_MotorIN1, OUTPUT);
     pinMode(m_MotorIN2, OUTPUT);
     pinMode(m_MotorIN3, OUTPUT);
     pinMode(m_MotorIN4, OUTPUT);
     pinMode(m_MotorENB, OUTPUT);

};
void MoonRovers::MovingSpeed(int p_motorSpeedA, int p_motorSpeedB)
{
    analogWrite(m_MotorENA, p_motorSpeedA);
    analogWrite(m_MotorENB, p_motorSpeedB);
};

void MoonRovers::StopMoving(){
    digitalWrite(m_MotorIN1, LOW);
    digitalWrite(m_MotorIN2, LOW);
    digitalWrite(m_MotorIN3, LOW);
    digitalWrite(m_MotorIN4, LOW);
};

void MoonRovers::DirectionY(){
    if(m_JoystickControl->getAxisY() > 20 ) MovingForward();
    else if(m_JoystickControl->getAxisY() < -20) MovingBackward();
    else StopMoving();

    m_MotorSpeedA = 120 + m_JoystickControl->getAxisY()/10;
    m_MotorSpeedB = 120 + m_JoystickControl->getAxisY()/10;
};

void MoonRovers::Differentiel(){
    int AxisX = m_JoystickControl->getAxisX()/5;
    if(AxisX > 20){ // A Droite
        analogWrite(m_MotorENB, m_MotorSpeedB - AxisX);
        analogWrite(m_MotorENA, m_MotorSpeedA);

    }
    else if(AxisX < -20){ // A Gauche
        analogWrite(m_MotorENB, m_MotorSpeedB );
        analogWrite(m_MotorENA, m_MotorSpeedA + AxisX);
    }
    else {
        analogWrite(m_MotorENB, 150);
        analogWrite(m_MotorENA, 150);
    }
};

void MoonRovers::MovingForward(){
    digitalWrite(m_MotorIN1, HIGH);
    digitalWrite(m_MotorIN2, LOW);
    digitalWrite(m_MotorIN3, HIGH);
    digitalWrite(m_MotorIN4, LOW);
};
void MoonRovers::MovingBackward(){
    digitalWrite(m_MotorIN1, LOW);
    digitalWrite(m_MotorIN2, HIGH);
    digitalWrite(m_MotorIN3, LOW);
    digitalWrite(m_MotorIN4, HIGH);
};
void MoonRovers::Moving()
{
    DirectionY();
    Differentiel();
};