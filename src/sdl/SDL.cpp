#include "SDL.h"

SDL::SDL(Uint32 flags) throw(InitError) {
    if (SDL_Init(flags) != 0)
        throw InitError();
    this->mainWindow = SDL_CreateWindow("SdlGame",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        1024, 768,
                                        SDL_WINDOW_FULLSCREEN_DESKTOP);
    this->mainRenderer = SDL_CreateRenderer(this->mainWindow,
                                            -1,
                                            SDL_RENDERER_ACCELERATED);
}

SDL::~SDL() {
    SDL_DestroyRenderer(this->mainRenderer);
    SDL_DestroyWindow(this->mainWindow);
    SDL_Quit();
}
