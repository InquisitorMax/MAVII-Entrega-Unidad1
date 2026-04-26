#include "Objeto.h"

Objeto::Objeto(b2World& world, b2Vec2 pos, float angle, b2BodyType type) {
    b2BodyDef bodyDef;
    bodyDef.type = type;
    bodyDef.position = pos;
    bodyDef.angle = angle; 

    body = world.CreateBody(&bodyDef);
}

Objeto::~Objeto() { // el b2world se encarga de limpiar los cuerpos al destruirse
    
}
