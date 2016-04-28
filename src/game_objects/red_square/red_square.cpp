#include "red_square.h"

namespace SDLGame_GameObjects {

    red_square::red_square(const std::string &name)
            : GameObject(name) {
        transform.x = 50;
        transform.y = 50;
        scripts.insert(scripts.end(), std::make_shared<MoveScript>());
    }

    red_square::~red_square() { }

    void red_square::Render(std::unique_ptr<SDL_Renderer, SDL_Deleter> &renderer) const {
        SDL_SetRenderDrawColor(renderer.get(), color.r, color.g, color.b, color.a);
        SDL_Rect rect = {transform.x, transform.y, w, h};
        SDL_RenderFillRect(renderer.get(), &rect);
    }

}
