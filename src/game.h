#pragma once
#ifndef GAME_H
#define GAME_H

#include <raylib.h>


typedef struct {
    Camera2D mainCamera;
} Game;

void update(Game *game, const float deltaTime);
void fixedUpdate(Game *game, const float deltaTime);
void drawGame(Game *game);
void drawUI(Game * game);
void render(Game *game);
void runGame(int windowWidth, int windowHeight, const char* windowTitle);
void initializeCamera(Camera2D *camera, int windowWidth, int windowHeight);

#endif // GAME_H
