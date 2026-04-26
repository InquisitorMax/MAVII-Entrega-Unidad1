#pragma once
#ifndef CAJA_H
#define CAJA_H

#include "Objeto.h"

class Caja : public Objeto {
private:
    float width;
    float height;
    Color color;

public:
    Caja(b2World& world, b2Vec2 pos, float angle, float w, float h, Color c);
    void Dibujar() override;
};

#endif
//agrego linea para probar subir a git
