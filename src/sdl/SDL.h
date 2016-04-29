#ifndef SDLGAME_SDL_H
#define SDLGAME_SDL_H

#include <memory>
#include "SDL2/SDL.h"
#include "../errors/Error_Container.h"

struct SDL_Deleter {
    void operator()(SDL_Window *p) const { SDL_DestroyWindow(p); }
    void operator()(SDL_Renderer *p) const { SDL_DestroyRenderer(p); }
    void operator()(SDL_Texture *p) const { SDL_DestroyTexture(p); }
};

class SDL : public SDLGame_Errors::ErrorContainer {
public:
    std::unique_ptr<SDL_Window, SDL_Deleter> &getMainWindow() {
        return mainWindow;
    }

    std::unique_ptr<SDL_Renderer, SDL_Deleter> &getMainRenderer() {
        return mainRenderer;
    }

    static SDL &GetInstance(Uint32 flags = 0) {
        static SDL instance(flags);
        return instance;
    }

    void BeginFrame();
    void EndFrame();

    SDL(SDL const &) = delete;
    void operator=(SDL const &) = delete;

private:
    Uint32 framecounter;
    Uint32 timecounter;
    std::unique_ptr<SDL_Window, SDL_Deleter> mainWindow;
    std::unique_ptr<SDL_Renderer, SDL_Deleter> mainRenderer;

    SDL(Uint32 flags = 0);
    virtual ~SDL();
};

#endif