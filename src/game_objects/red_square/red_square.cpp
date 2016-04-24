#include "red_square.h"

namespace SDLGame_GameObjects {

    red_square::red_square(const std::string &name)
            : GameObject(name) {
        transform.x = 50;
        transform.y = 50;
        MoveScript *moveScript = new MoveScript();
        moveScript->Start(this);
        scripts.insert(scripts.end(), moveScript);
    }

    red_square::~red_square() {

    }

    void red_square::Render(SDL_Renderer *renderer) const {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_Rect rect = {this->transform.x, this->transform.y, w, h};
        SDL_RenderFillRect(renderer, &rect);
    }

}
