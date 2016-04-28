#include <SDL2/SDL_timer.h>
#include "../sdl/SDL.h"
#include "Scene.h"

Scene::Scene(const std::string &name)
        : name(name) {

}

Scene::~Scene() {
    for (auto object : objects) {
        object.second.reset();
    }
}

void Scene::add_object(std::shared_ptr<SDLGame_GameObjects::GameObject> &object) {
    objects.insert(std::pair<std::string, std::shared_ptr<SDLGame_GameObjects::GameObject>>(object->getName(), object));
}

void Scene::run() {
    for (auto object : objects) {
        object.second->Start();
    }
    auto &renderer = SDL::GetInstance().getMainRenderer();
    Uint32 frametime;
    SDL_Event event;
    while (true) {
        frametime = SDL_GetTicks();
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }

        for (auto object : objects) {
            object.second->Update();
        }

        Uint32 newFrameTime = SDL_GetTicks();
        if (!SDL_TICKS_PASSED(newFrameTime, frametime + 15)) {
            SDL_Delay((frametime + 15) - newFrameTime);
        }
        SDL_SetRenderDrawColor(renderer.get(), 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer.get());
        for (auto object : objects) {
            object.second->Render(renderer);
        }
        SDL_RenderPresent(renderer.get());
    }
}

