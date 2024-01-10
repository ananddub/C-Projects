#include <SDL2/SDL.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
void drawCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius)
        {
        int x = radius - 1;
        int y = 0;
        int dx = 1;
        int dy = 1;
        int err = dx - (radius << 1);
        while (x >= y)
                {
                SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
                SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
                SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);
                SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
                SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
                SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
                SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
                SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
                if (err <= 0)
                        {
                        y++;
                        err += dy;
                        dy += 2;
                        }
                if (err > 0)
                        {
                        x--;
                        dx += 2;
                        err += dx - (radius << 1);
                        }
                }
        }
int main()
        {
        SDL_Init(SDL_INIT_VIDEO);
        SDL_Window *window = SDL_CreateWindow("SDL Circle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                              SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        int centerX = SCREEN_WIDTH / 2;
        int centerY = SCREEN_HEIGHT / 2;
        int radius = 100;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        drawCircle(renderer, centerX, centerY, radius);
        SDL_RenderPresent(renderer);
        SDL_Event event;
        int quit = 0;
        while (!quit)
                {
                while (SDL_PollEvent(&event))
                        {
                        if (event.type == SDL_QUIT)
                                quit = 1;
                        }
                }
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
        }
