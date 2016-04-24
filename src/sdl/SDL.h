#ifndef SDLGAME_SDL_H
#define SDLGAME_SDL_H

#include "SDL2/SDL.h"
#include "Init_Exception.h"

class SDL {
public:
    SDL_Window *getMainWindow() const {
        return mainWindow;
    }

    SDL_Renderer *getMainRenderer() const {
        return mainRenderer;
    }

    static SDL &getInstance(Uint32 flags = 0) throw(InitError) {
        static SDL instance(flags);
        return instance;
    }

    SDL(SDL const &) = delete;

    void operator=(SDL const &) = delete;

private:
    SDL_Window *mainWindow;
    SDL_Renderer *mainRenderer;

    SDL(Uint32 flags = 0) throw(InitError);

    virtual ~SDL();
};

#endif