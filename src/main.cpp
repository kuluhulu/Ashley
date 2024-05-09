#include <iostream>
#include "SDL/SDL.h"

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    const uint32_t width = 800; 
    const uint32_t height = 600; 

    SDL_Window* window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE|SDL_WINDOW_VULKAN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    bool ShouldClose = false;
    SDL_Event event;

    while(!ShouldClose) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                ShouldClose = true;
            }
        }
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}