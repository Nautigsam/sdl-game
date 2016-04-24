#ifndef SDLGAME_RED_SQUARE_H
#define SDLGAME_RED_SQUARE_H

#include "../Game_Object.h"
#include "Move_Script.h"

namespace SDLGame_GameObjects {

    class red_square : public GameObject {
        friend class MoveScript;
    public:
        red_square(const std::string &name);
        virtual ~red_square();
        virtual void Render(SDL_Renderer *renderer) const override;

    private:
        int w;
        int h;
        SDL_Color color;
    };

}

#endif //SDLGAME_RED_SQUARE_H
