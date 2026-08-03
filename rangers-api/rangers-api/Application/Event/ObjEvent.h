#pragma once

namespace app{
    class ObjEvent : public hh::game::GameObject, public evt::EventPlayerListener {
    public:
        evt::EventSetupData eventSetupData;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
        virtual void EPL_UnkFunc5() override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjEvent);
    };
}
