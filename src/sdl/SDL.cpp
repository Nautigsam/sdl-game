#include <iostream>
#include "SDL.h"

SDL::SDL(Uint32 flags) :
    framecounter(0), timecounter(0) {
    if (SDL_Init(flags) != 0) {
        SetError(std::make_shared<SDLGame_Errors::Error>(SDLGame_Errors::SDLGAME_ERROR_TYPE::SDL_INIT_ERROR));
        return;
    }
    mainWindow = std::unique_ptr<SDL_Window, SDL_Deleter>(SDL_CreateWindow("SdlGame",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  1024, 768,
                                  SDL_WINDOW_FULLSCREEN_DESKTOP),
                                  SDL_Deleter()
                                );
    if (!mainWindow) {
        SetError(std::make_shared<SDLGame_Errors::Error>(SDLGame_Errors::SDLGAME_ERROR_TYPE::SDL_WINDOW_ERROR));
        return;
    }
    mainRenderer = std::unique_ptr<SDL_Renderer, SDL_Deleter>(SDL_CreateRenderer(mainWindow.get(),
                                      -1,
                                      SDL_RENDERER_ACCELERATED),
                                      SDL_Deleter()
                                );
    if (!mainRenderer) {
        SetError(std::make_shared<SDLGame_Errors::Error>(SDLGame_Errors::SDLGAME_ERROR_TYPE::SDL_RENDERER_ERROR));
        return;
    }
}

SDL::~SDL() {
    mainRenderer.reset();
    mainWindow.reset();
    SDL_Quit();
}

void SDL::BeginFrame() {
    SDL_SetRenderDrawColor(mainRenderer.get(), 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(mainRenderer.get());
}

void SDL::EndFrame() {
    SDL_RenderPresent(mainRenderer.get());
    framecounter++;
    if (SDL_TICKS_PASSED(SDL_GetTicks(), timecounter + 1000)) {
        std::cout << framecounter << " fps" << std::endl;
        framecounter = 0;
        timecounter = SDL_GetTicks();
    }
}