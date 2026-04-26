#include "Caja.h"

Caja::Caja(b2World& world, b2Vec2 pos, float angle, float w, float h, Color c)
    : Objeto(world, pos, angle, b2_dynamicBody) {

    width = w;
    height = h;
    color = c;

    // forma 
    b2PolygonShape shape;
    shape.SetAsBox(w / 4.0f, h / 2.0f);

    // propiedades físicas 
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;     // para la masa 
    fixtureDef.friction = 0.4f;    // para el agarre 
    fixtureDef.restitution = 0.2f; // para el rebote 

    body->CreateFixture(&fixtureDef);
}

void Caja::Dibujar() {
    b2Vec2 pos = GetPosicion();
    float angle = GetAngulo() * RAD2DEG; // radianes a grados

    Rectangle rect = { pos.x, pos.y, width, height };
    Vector2 origin = { width / 2.0f, height / 2.0f };

    DrawRectanglePro(rect, origin, angle, color);
}
