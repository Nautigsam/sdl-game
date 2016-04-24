#include <SDL2/SDL_timer.h>
#include "../sdl/SDL.h"
#include "Scene.h"

Scene::Scene(const std::string &name)
        : name(name), objects() {

}

Scene::~Scene() {
    for (auto it = objects.begin(); it != objects.end(); it++) {
        delete it->second;
    }
}

void Scene::add_object(SDLGame_GameObjects::GameObject *object) {
    objects.insert(std::pair<std::string, SDLGame_GameObjects::GameObject*>(object->getName(), object));
}

void Scene::run() {
    SDL_Renderer *renderer = SDL::getInstance().getMainRenderer();
    Uint32 frametime;
    SDL_Event event;
    while (true) {
        frametime = SDL_GetTicks();
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }

        for (auto it = objects.begin(); it != objects.end(); it++) {
            it->second->Update();
        }

        Uint32 newFrameTime = SDL_GetTicks();
        if (!SDL_TICKS_PASSED(newFrameTime, frametime + 15)) {
            SDL_Delay((frametime + 15) - newFrameTime);
        }
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);
        for (auto it = objects.begin(); it != objects.end(); it++) {
            it->second->Render(renderer);
        }
        SDL_RenderPresent(renderer);
    }
}

