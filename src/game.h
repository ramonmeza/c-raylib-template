#pragma once

#include <raylib.h>


typedef struct {
    Camera2D mainCamera;
} Game;

void update(Game *game, const float deltaTime);
void fixedUpdate(Game *game, const float deltaTime);
void drawGame(Game *game);
void drawUI(Game * game);
void render(Game *game);
