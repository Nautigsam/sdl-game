#ifndef SDLGAME_SCRIPT_COMPONENT_H
#define SDLGAME_SCRIPT_COMPONENT_H

#include <memory>

namespace SDLGame_GameObjects {
    class GameObject;
}

namespace SDLGame_Components {

    class ScriptComponent {
    public:
        virtual ~ScriptComponent() {}
        virtual void Start(std::shared_ptr<SDLGame_GameObjects::GameObject> gameobject) = 0;
        virtual void Update(std::shared_ptr<SDLGame_GameObjects::GameObject> gameobject) = 0;
    };

}

#endif //SDLGAME_SCRIPT_COMPONENT_H
