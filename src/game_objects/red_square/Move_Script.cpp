#include "Move_Script.h"
#include "red_square.h"

namespace SDLGame_GameObjects {

    void MoveScript::Start(std::shared_ptr<GameObject> gameobject) {
        std::shared_ptr<red_square> go = std::dynamic_pointer_cast<red_square>(gameobject);

        go->w = 100;
        go->h = 100;
        go->color = {255, 0, 0, 255};
    }

    void MoveScript::Update(std::shared_ptr<GameObject> gameobject) {
        std::shared_ptr<red_square> go = std::dynamic_pointer_cast<red_square>(gameobject);

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_W]) {
            go->transform.y -= 20;
        }
        if (state[SDL_SCANCODE_A]) {
            go->transform.x -= 20;
        }
        if (state[SDL_SCANCODE_S]) {
            go->transform.y += 20;
        }
        if (state[SDL_SCANCODE_D]) {
            go->transform.x += 20;
        }
    }

}