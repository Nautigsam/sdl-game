#ifndef SDLGAME_SCRIPT_COMPONENT_H
#define SDLGAME_SCRIPT_COMPONENT_H

namespace SDLGame_GameObjects {
    class GameObject;
}

namespace SDLGame_Components {

    class ScriptComponent {
    public:
        virtual ~ScriptComponent() {}
        virtual void Start(SDLGame_GameObjects::GameObject *gameobject) = 0;
        virtual void Update(SDLGame_GameObjects::GameObject *gameobject) = 0;
    };

}

#endif //SDLGAME_SCRIPT_COMPONENT_H
