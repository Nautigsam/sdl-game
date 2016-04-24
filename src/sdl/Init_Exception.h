#ifndef SDLGAME_INIT_EXCEPTION_H
#define SDLGAME_INIT_EXCEPTION_H

#include <exception>
#include <string>

class InitError: public std::exception {
    public:
        InitError();
        InitError(const std::string&);
        virtual ~InitError() throw();
        virtual const char* what() const throw();
    private:
        std::string msg;
};

#endif