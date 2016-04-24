#ifndef SDLGAME_GAME_OBJECT_H
#define SDLGAME_GAME_OBJECT_H

#include <string>
#include <list>
#include <SDL2/SDL_system.h>
#include "../components/Script_Component.h"
#include "../components/Transform_Component.h"

namespace SDLGame_GameObjects {

    class GameObject {
    public:
        const std::string &getName() const {
            return name;
        }
        GameObject(const std::string &name);
        virtual ~GameObject();
        virtual void Render(SDL_Renderer *renderer) const = 0;
        void Update();

    protected:
        SDLGame_Components::TransformComponent transform;
        std::list<SDLGame_Components::ScriptComponent*> scripts;

    private:
        const std::string name;
    };

}

#endif //SDLGAME_GAME_OBJECT_H
