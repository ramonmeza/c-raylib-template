#include <math.h>
#include <stdint.h>

#include <raylib.h>
#include <raymath.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include "constants.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "God Game"

typedef struct {
    Camera2D mainCamera;
} Game;

float min_value(float x, float y);
float max_value(float x, float y);
void update(Game *game, const float deltaTime);
void fixedUpdate(Game *game, const float deltaTime);
void drawGame(Game *game);
void drawUI(Game * game);
void render(Game *game);

int main(int argc, char* argv[]) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetRandomSeed(config.RAND_SEED);
    
    Game game = {0};
    
    // init main camera
    game.mainCamera.offset.x = WINDOW_WIDTH / 2.0;
    game.mainCamera.offset.y = WINDOW_HEIGHT / 2.0;
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
    return 0;
}

float min_value(float x, float y) {
    return x <= y ? x : y;
}

float max_value(float x, float y) {
    return x >= y ? x : y;
}

void update(Game *game, const float deltaTime) {
}

void fixedUpdate(Game *game, const float deltaTime) {
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
