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
            script.reset();
        }
    }
    void GameObject::Start() {
        for (auto script : scripts) {
            if (script != nullptr) {
                script->Start(shared_from_this());
            }
        }
    }
    void GameObject::Update() {
        for (auto script : scripts) {
            if (script != nullptr) {
                script->Update(shared_from_this());
            }
        }
    }

}