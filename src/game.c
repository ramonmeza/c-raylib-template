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

void runGame(int windowWidth, int windowHeight, const char* windowTitle) {
    InitWindow(windowWidth, windowHeight, windowTitle);
    SetRandomSeed(config.RAND_SEED);
    
    Game game = {0};
    
    // init main camera
    game.mainCamera.offset.x = windowWidth / 2.0;
    game.mainCamera.offset.y = windowHeight / 2.0;
    game.mainCamera.target.x = 0;
    game.mainCamera.target.y = 0;
    game.mainCamera.rotation = 0.0;
    game.mainCamera.zoom = 1.0;

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

void drawGame(Game *game) {
    BeginMode2D(game->mainCamera);
    EndMode2D();
}

void drawUI(Game * game) {
    DrawFPS(10, 10);
}

void render(Game *game) {
    BeginDrawing();
    ClearBackground(BLACK);
    drawGame(game);
    drawUI(game);
    EndDrawing();
}
