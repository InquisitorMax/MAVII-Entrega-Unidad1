#pragma once
#ifndef OBJETO_H
#define OBJETO_H

#include "raylib.h"
#include <box2d.h>

class Objeto {
protected:
    b2Body* body;

public:
    Objeto(b2World& world, b2Vec2 pos, float angle, b2BodyType type);
    virtual ~Objeto();

    virtual void Dibujar() = 0; 
    b2Vec2 GetPosicion() const { return body->GetPosition(); }
    float GetAngulo() const { return body->GetAngle(); }
};

#endif
