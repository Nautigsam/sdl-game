#ifndef SDLGAME_GAME_OBJECT_H
#define SDLGAME_GAME_OBJECT_H

#include <string>
#include <list>
#include <SDL2/SDL_system.h>
#include <memory>
#include "../utils/Enable_Shared_This.h"
#include "../components/Script_Component.h"
#include "../components/Transform_Component.h"
#include "../sdl/SDL.h"

namespace SDLGame_GameObjects {

    class GameObject : public EnableSharedThis<GameObject> {
    public:
        const std::string &getName() const {
            return name;
        }
        GameObject(const std::string &name);
        virtual ~GameObject();
        virtual void Render(std::unique_ptr<SDL_Renderer, SDL_Deleter> &renderer) const = 0;
        void Start();
        void Update();

    protected:
        SDLGame_Components::TransformComponent transform;
        std::list<std::shared_ptr<SDLGame_Components::ScriptComponent>> scripts;

    private:
        const std::string name;
    };

}

#endif //SDLGAME_GAME_OBJECT_H
