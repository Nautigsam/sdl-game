#ifndef SDLGAME_ENABLE_SHARED_THIS_H
#define SDLGAME_ENABLE_SHARED_THIS_H

#include <memory>

class VirtEnableSharedThis :
        public std::enable_shared_from_this<VirtEnableSharedThis>
{
public:
    virtual ~VirtEnableSharedThis() {}
};

template <class T>
class EnableSharedThis : virtual public VirtEnableSharedThis
{
public:
    std::shared_ptr<T> shared_from_this() {
        return std::dynamic_pointer_cast<T>(VirtEnableSharedThis::shared_from_this());
    }
};

#endif //SDLGAME_ENABLE_SHARED_THIS_H
