#define SDL_MAIN_HANDLED

#include <iostream>
#include "sdl/SDL.h"
#include "scenes/Scene.h"
#include "game_objects/red_square/red_square.h"

int main(int argc, char *argv[]) {
    SDL_SetMainReady();
    bool error = SDL::GetInstance(SDL_INIT_VIDEO | SDL_INIT_TIMER).HasError();
    if (error) {
        std::cout << "An error occured: " << SDL::GetInstance().GetLastError() << std::endl;
        exit(EXIT_FAILURE);
    }

    auto redSquare = std::make_shared<SDLGame_GameObjects::red_square>("red square");

    Scene mainScene("main");
    auto ptrToAdd = std::dynamic_pointer_cast<SDLGame_GameObjects::GameObject>(redSquare);
    mainScene.add_object(ptrToAdd);

    mainScene.run();

    exit(EXIT_SUCCESS);
}