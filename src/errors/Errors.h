#ifndef SDLGAME_ERRORS_H
#define SDLGAME_ERRORS_H

#include <string>
#include <map>

namespace SDLGame_Errors {

    enum class SDLGAME_ERROR_TYPE {
        GENERIC_ERROR = 0,
        SDL_INIT_ERROR,
        SDL_WINDOW_ERROR,
        SDL_RENDERER_ERROR
    };

    class Error {
    public:
        SDLGAME_ERROR_TYPE getType() const {
            return type;
        }

        const std::string &getMessage() const {
            return message;
        }

        Error(SDLGAME_ERROR_TYPE type);
        Error(SDLGAME_ERROR_TYPE type, const std::string &message);
        virtual ~Error();

        friend std::ostream &operator<<(std::ostream &os, const Error &error);

    private:
        SDLGAME_ERROR_TYPE type;
        std::string message;
        static const std::map<SDLGAME_ERROR_TYPE, std::string> DEFAULT_MESSAGES;
    };

}

#endif //SDLGAME_ERRORS_H
