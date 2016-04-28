#include "Errors.h"

namespace SDLGame_Errors {

    Error::Error(SDLGAME_ERROR_TYPE type)
        : Error(type, Error::DEFAULT_MESSAGES.at(type)) { }

    Error::Error(SDLGAME_ERROR_TYPE type, const std::string &message)
        : type(type), message(message) { }

    Error::~Error() { }

    std::ostream &operator<<(std::ostream &os, const Error &error) {
        os << error.message;
        return os;
    }

    const std::map<SDLGAME_ERROR_TYPE, std::string> Error::DEFAULT_MESSAGES =  {
            {SDLGAME_ERROR_TYPE::GENERIC_ERROR, "Generic error"},
            {SDLGAME_ERROR_TYPE::SDL_INIT_ERROR, "SDL init error"},
            {SDLGAME_ERROR_TYPE::SDL_WINDOW_ERROR, "SDL window error"},
            {SDLGAME_ERROR_TYPE::SDL_RENDERER_ERROR, "SDL renderer error"}
    };

}