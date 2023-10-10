#ifndef Motores_H
#define Motores_H

class Motores {
private:
    int pinesMotor[4];
    float delayEntrePasos;

public:
    Motores(int pins[], float delaySteps);
    void Bobina();
    void medio_paso();
};

#endif // Motores_H
