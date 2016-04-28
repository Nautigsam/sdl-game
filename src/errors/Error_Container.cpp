#include "Error_Container.h"

namespace SDLGame_Errors {

    ErrorContainer::ErrorContainer()
        : hasError(false), lastError() { }
    ErrorContainer::~ErrorContainer() { }

    std::shared_ptr<Error> ErrorContainer::GetLastError() {
        hasError = false;
        return lastError;
    }

    void ErrorContainer::SetError(std::shared_ptr<Error> error) {
        hasError = true;
        lastError = error;
    }

}