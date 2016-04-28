#ifndef SDLGAME_SCENE_H
#define SDLGAME_SCENE_H

#include <string>
#include <map>
#include "../game_objects/Game_Object.h"

class Scene {
public:
    const std::string &getName() const {
        return name;
    }

    Scene(const std::string &name = "");
    virtual ~Scene();

    void add_object(std::shared_ptr<SDLGame_GameObjects::GameObject> &object);
    void run();
private:
    const std::string name;
    std::map<std::string, std::shared_ptr<SDLGame_GameObjects::GameObject>> objects;
};


#endif //SDLGAME_SCENE_H
