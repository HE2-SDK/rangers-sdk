#pragma once

namespace app{
    class ObjStartPosition : public hh::game::GameObject {
    public:
        virtual bool ProcessMessage(hh::fnd::Message& message) override;  

        GAMEOBJECT_CLASS_DECLARATION(ObjStartPosition);
    };
}
