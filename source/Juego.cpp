#include "Juego.h"

Juego::Juego() {
    InitWindow(screenWidth, screenHeight, "Mavix Despierta");
    InitAudioDevice();
    SetTargetFPS(60);

    b2Vec2 gravity(0.0f, 9.8f);
    world = new b2World(gravity);

    anguloPrevisualizacion = 0.0f;
    tiempoMensaje = 5.0f;
    contadorCajas = 0;

    // hago a Alakazam como textura visual solamente (sin cuerpo físico digamos)
    spriteAlakazam = LoadTexture("Assets/Alakazam.png");
    posAlakazam = { 850.0f, 480.0f }; 
    escalaAlakazam = 0.2f; 
    
    // cargo los audios
    sonidoInicio = LoadSound("Assets/GritoAlakazam.wav");   // se reproduce una vez
    musicaFondo = LoadMusicStream("Assets/CalleVictoria.mp3"); // se reproduce en bucle
    musicaFondo.looping = true;
    musicaIniciada = false;
    temporizadorMusica = 1.0f; 

    PlaySound(sonidoInicio);
    // piso
    b2BodyDef groundDef;
    groundDef.position.Set(screenWidth / 2.0f, screenHeight - 20.0f);
    b2Body* groundBody = world->CreateBody(&groundDef);

    b2PolygonShape groundShape;
    groundShape.SetAsBox(screenWidth / 2.0f, 20.0f);
    groundBody->CreateFixture(&groundShape, 0.0f);
}

Juego::~Juego() {
    
    for (Caja* c : cajas) {
        delete c;
    }
    UnloadTexture(spriteAlakazam);
    UnloadSound(sonidoInicio);
    UnloadMusicStream(musicaFondo);
    CloseAudioDevice(); 
    delete world;
    CloseWindow();
}

void Juego::ProcesarEntrada() {
    if (IsKeyDown(KEY_LEFT)) anguloPrevisualizacion -= 0.05f;
    if (IsKeyDown(KEY_RIGHT)) anguloPrevisualizacion += 0.05f;

    if (IsKeyPressed(KEY_SPACE)) {
        
        Caja* nuevaCaja = new Caja(*world, { (float)screenWidth / 2, 50.0f },
            anguloPrevisualizacion, 40.0f, 20.0f, SKYBLUE);
        cajas.push_back(nuevaCaja);
        contadorCajas++; // contador
    }
}

void Juego::Actualizar() {
    world->Step(1.0f / 60.0f, 8, 3);
    if (tiempoMensaje > 0) tiempoMensaje -= GetFrameTime();

    // para iniciar la música 
    if (!musicaIniciada) {
        temporizadorMusica -= GetFrameTime();
        if (temporizadorMusica <= 0) {
            PlayMusicStream(musicaFondo);
            musicaIniciada = true;
        }
    }
    else {
        UpdateMusicStream(musicaFondo); // para que la música siga sonando
    }
}


void Juego::Dibujar() {
    BeginDrawing();
    ClearBackground({ 110, 100, 215, 255 });

    DrawRectangle(0, screenHeight - 40, screenWidth, 40, DARKGREEN);
    DrawTextureEx(spriteAlakazam, posAlakazam, 0.0f, escalaAlakazam, WHITE);

    for (Caja* caja : cajas) {
        caja->Dibujar(); 
    }

    // contador de cajas
    DrawText(TextFormat("Cajas: %i", contadorCajas), screenWidth - 150, 20, 25, RAYWHITE);
    
    if (contadorCajas >= 200) {
       
        DrawRectangle(150, 280, 700, 60, Fade(RED, 0.8f));
        DrawRectangleLines(150, 280, 700, 60, MAROON);

        
        DrawText("Ya creaste 200 cajas... ¿en serio queres crear mas?",
            180, 300, 24, RAYWHITE);
    }
    // mouse
    Vector2 mousePos = GetMousePosition();
    DrawText(TextFormat("Mouse: [%.0f, %.0f]", mousePos.x, mousePos.y), 10, 70, 18, YELLOW);

    if (tiempoMensaje > 0) {
        DrawRectangle(0, 200, screenWidth, 60, Fade(BLACK, 0.6f));
        DrawText("Alakazam usa sus poderes psiquicos para crear cajas y modificar su orientacion",
            50, 220, 20, GOLD);
    }

    DrawText("Flechas: para rotar las cajas | Espacio: para crear una caja", 10, 10, 20, RAYWHITE);
    DrawText(TextFormat("Angulo: %.2f rad", anguloPrevisualizacion), 10, 40, 20, LIGHTGRAY);

    EndDrawing();
}

void Juego::Ejecutar() {
    while (!WindowShouldClose()) {
        ProcesarEntrada();
        Actualizar();
        Dibujar();
    }
}
