#pragma once
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

typedef struct {
    int RAND_SEED;
    float FIXED_UPDATE_TIME;
    float CAMERA_SPEED;
    float CAMERA_ROTATION_SPEED;
    float CAMERA_ZOOM_MIN;
    float CAMERA_ZOOM_MAX;
    int TILE_WIDTH;
    int TILE_HEIGHT;
    float EMPTY_GRID_LINE_THICKNESS;
} Configuration;

const Configuration config = {
    .RAND_SEED = 42069,
    .FIXED_UPDATE_TIME = 1.0 / 60.0,
};

#endif // CONFIGURATION_H
