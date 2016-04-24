#define SDL_MAIN_HANDLED

#include <iostream>
#include "sdl/SDL.h"
#include "scenes/Scene.h"
#include "game_objects/red_square/red_square.h"

int main(int argc, char *argv[]) {
    SDL_SetMainReady();
    try {
        SDL::getInstance(SDL_INIT_VIDEO | SDL_INIT_TIMER);

        SDLGame_GameObjects::red_square *redSquare = new SDLGame_GameObjects::red_square("red square");
        Scene mainScene("main");
        mainScene.add_object(redSquare);

        mainScene.run();

        return 0;
    }
    catch (const InitError &err) {
        std::cerr
        << "Error while initializing SDL:  "
        << err.what() << std::endl;
    }
}