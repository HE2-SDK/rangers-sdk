#pragma once

namespace app {
    class ObjWarpTrigger : public hh::game::GameObject, public PassPlaneListener {
    public:
        PassPlaneTrigger trigger;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
        virtual void OnEnter(char playedId) override;
        virtual void OnLeave(char playedId) override {}

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjWarpTrigger);
    };
}
