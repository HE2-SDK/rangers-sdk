#pragma once

namespace app::game {
    hh::game::ObjInfo* GetObjInfo(hh::game::GameManager* gameManager, const char* name);

    template<typename T>
    T* GetObjInfo(hh::game::GameManager* gameManager) {
        return (T*)GetObjInfo(gameManager, T::GetClass()->name);
    }

    void ResetPropertyFlag(hh::game::GameObject* object, unsigned int propertyId, unsigned char flag);
    void SetPropertyFlag(hh::game::GameObject* object, unsigned int propertyId, unsigned char flag);
    bool IsPropertyFlagSet(hh::game::GameObject* object, unsigned int propertyId, unsigned char flag);
}
