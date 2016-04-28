#ifndef SDLGAME_MOVE_SCRIPT_H
#define SDLGAME_MOVE_SCRIPT_H

#include "../../components/Script_Component.h"
#include "../Game_Object.h"

namespace SDLGame_GameObjects {

    class MoveScript : public SDLGame_Components::ScriptComponent {

    public:
        virtual void Start(std::shared_ptr<GameObject> gameobject) override;
        virtual void Update(std::shared_ptr<GameObject> gameobject) override;
    };

}

#endif //SDLGAME_MOVE_SCRIPT_H
