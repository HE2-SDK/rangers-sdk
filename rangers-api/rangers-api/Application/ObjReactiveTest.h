#pragma once

namespace app{
    class ObjReactiveTest : public hh::game::GameObject, public game::ReactiveListener {
    public:
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
        virtual void RemoveCallback(hh::game::GameManager* gameManager) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjReactiveTest)
    };
}
