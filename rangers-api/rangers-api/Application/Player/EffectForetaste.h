#pragma once

namespace app::player {
    class EffectForetaste : public PlayerEffect {
    public:
        csl::ut::MoveArray<void*> unk48;
        uint32_t qword68;
        hh::fnd::Handle<hh::game::GameObject> foretasteSignObject;
        csl::fnd::Mutex mutex;

        CREATE_FUNC(EffectForetaste, hh::game::GameObject* playerObject, PlayerVisual* playerVisual);

        virtual unsigned int GetNameHash() const override;
        virtual void Update(int64_t a2, float deltaTime) override;
    };
}
