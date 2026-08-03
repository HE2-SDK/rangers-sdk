#pragma once

namespace app{
    class ObjEventPlayTest : public hh::game::GameObject{
    public:
        evt::EventSetupData eventSetupData;
        int unk0;
        Timer unkTimer;
        char unk3;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjEventPlayTest)
    };
}
