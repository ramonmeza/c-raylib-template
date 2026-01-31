#include "game.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "C Raylib Game Template"

extern void runGame(int windowWidth, int windowHeight, const char* windowTitle);

int main(int argc, char* argv[]) {
    runGame(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    return 0;
}
