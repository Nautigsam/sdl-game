#ifndef SDLGAME_ERROR_CONTAINER_H
#define SDLGAME_ERROR_CONTAINER_H

#include <memory>
#include <queue>
#include "Errors.h"

namespace SDLGame_Errors {

    class ErrorContainer {
    public:
        bool HasError() const {
            return hasError;
        }

        ErrorContainer();
        virtual ~ErrorContainer();
        std::shared_ptr<Error> GetLastError();

    protected:
        void SetError(std::shared_ptr<Error> error);

    private:
        bool hasError;
        std::shared_ptr<Error> lastError;
    };

}

#endif //SDLGAME_ERROR_CONTAINER_H
