#ifndef SDLGAME_RED_SQUARE_H
#define SDLGAME_RED_SQUARE_H

#include "../Game_Object.h"
#include "Move_Script.h"

namespace SDLGame_GameObjects {

    class red_square : public GameObject, public EnableSharedThis<red_square> {
        friend class MoveScript;
    public:
        using EnableSharedThis<red_square>::shared_from_this;

        red_square(const std::string &name);
        virtual ~red_square();
        virtual void Render(std::unique_ptr<SDL_Renderer, SDL_Deleter> &renderer) const override;

    private:
        int w;
        int h;
        SDL_Color color;
    };

}

#endif //SDLGAME_RED_SQUARE_H
