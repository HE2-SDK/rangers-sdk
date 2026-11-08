#pragma once

namespace app::player{
    class EffectOverlay : public PlayerEffect{
    public:
        hh::fnd::Handle<ObjOverlayEffect> obj;
        char flags;
        app::Timer timer;

        virtual unsigned int GetNameHash() const override;
        virtual void Update(int64_t a2, float deltaTime) override;

        void SpawnEffect();

        CREATE_FUNC(EffectOverlay, hh::game::GameObject* playerObject, PlayerVisual* playerVisual);
    };
}
