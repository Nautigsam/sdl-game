#include <iostream>
#include "Game_Object.h"

namespace SDLGame_GameObjects {

    GameObject::GameObject(const std::string &name)
            : name(name) {
        transform.x = 0;
        transform.y = 0;
    }
    GameObject::~GameObject() {
        for (auto script : scripts) {
            delete script;
        }
    }
    void GameObject::Update() {
        for (auto script : scripts) {
            if (script != nullptr) {
                script->Update(this);
            }
        }
    }

}