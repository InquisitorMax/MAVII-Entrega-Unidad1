#pragma once
#ifndef JUEGO_H
#define JUEGO_H

#include "Caja.h"
#include <vector>

class Juego {
private:
    const int screenWidth = 1000;
    const int screenHeight = 600;

    b2World* world;
    std::vector<Caja*> cajas;

    Texture2D spriteAlakazam;
    Vector2 posAlakazam;
    float escalaAlakazam; 
    
    // audio
    Sound sonidoInicio;
    Music musicaFondo;
    bool musicaIniciada;
    float temporizadorMusica; 
    float anguloPrevisualizacion;
    float tiempoMensaje;
    int contadorCajas;

public:
    Juego();
    ~Juego();
    void Ejecutar();
    void ProcesarEntrada();
    void Actualizar();
    void Dibujar();
};

#endif

