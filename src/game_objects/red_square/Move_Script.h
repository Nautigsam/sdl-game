#ifndef SDLGAME_MOVE_SCRIPT_H
#define SDLGAME_MOVE_SCRIPT_H

#include "../../components/Script_Component.h"

namespace SDLGame_GameObjects {

    class MoveScript : public SDLGame_Components::ScriptComponent {

    public:
        virtual void Start(GameObject *gameobject) override;
        virtual void Update(GameObject *gameobject) override;
    };

}

#endif //SDLGAME_MOVE_SCRIPT_H
