#include <SDL2/SDL.h>
#include <math.h>

void drawCircle(SDL_Renderer *ren, int x_center, int y_center, int radius) {
    for (float theta = 0; theta < 2 * M_PI; theta += 0.01) {
        int x = x_center + radius * cos(theta);
        int y = y_center + radius * sin(theta);
        SDL_RenderDrawPoint(ren, x, y);
    }
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Circle Drawing", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL) {
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255); // Set to white color

    drawCircle(ren, 320, 240, 100);

    SDL_RenderPresent(ren);

    SDL_Delay(5000);

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
