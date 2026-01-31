#include <math.h>
#include <stdint.h>

#include <raylib.h>
#include <raymath.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include "configuration.h"
#include "game.h"


void update(Game *game, const float deltaTime) {
    // add code here
}

void fixedUpdate(Game *game, const float deltaTime) {
    // add code here
}

void drawGame(Game *game) {
    BeginMode2D(game->mainCamera);
    // add drawing code here
    EndMode2D();
}

void drawUI(Game * game) {
    // add UI drawing code here
    
    DrawFPS(10, 10);
}

void runGame(int windowWidth, int windowHeight, const char* windowTitle) {
    InitWindow(windowWidth, windowHeight, windowTitle);
    SetRandomSeed(config.RAND_SEED);
    
    Game game = {0};
    
    // init main camera
    initializeCamera(&game.mainCamera, windowWidth, windowHeight);

    float fixedUpdateAccum = 0.0;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        // frame update
        update(&game, deltaTime);
        
        // fixed update
        fixedUpdateAccum += deltaTime;
        while (fixedUpdateAccum >= config.FIXED_UPDATE_TIME) {
            fixedUpdateAccum -= config.FIXED_UPDATE_TIME;
            fixedUpdate(&game, config.FIXED_UPDATE_TIME);
        }
        render(&game);
    }
    CloseWindow();
}

void render(Game *game) {
    BeginDrawing();
    ClearBackground(BLACK);
    drawGame(game);
    drawUI(game);
    EndDrawing();
}

void initializeCamera(Camera2D *camera, int windowWidth, int windowHeight) {
    camera->offset = (Vector2){ windowWidth / 2.0f, windowHeight / 2.0f };
    camera->target = (Vector2){ 0.0f, 0.0f };
    camera->rotation = 0.0f;
    camera->zoom = 1.0f;
}
