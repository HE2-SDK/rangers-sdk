#pragma once

namespace app{
    class ObjBlockObjectTest : public hh::game::GameObject {
    public:
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjBlockObjectTest)
    };
}
