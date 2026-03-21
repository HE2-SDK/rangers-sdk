#pragma once

namespace app::player {
    class EffectParticleLocation : public PlayerEffect, public hh::animeff::ParticleLocatorListener {
    public:
        csl::ut::MoveArray<void*> unk201;
        short word70;
        csl::ut::MoveArray<void*> unk202;
        uint8_t flags;

        CREATE_FUNC(EffectParticleLocation, hh::game::GameObject* playerObject, PlayerVisual* playerVisual);

        virtual unsigned int GetNameHash() const override;
        virtual void Update(int64_t a2, float deltaTime) override;
        virtual void PreCreateParticle(hh::animeff::GOCParticleLocator* gocParticleLocator, PreCreateParticleInfo& preCreateParticleInfo) override;
    };
}
