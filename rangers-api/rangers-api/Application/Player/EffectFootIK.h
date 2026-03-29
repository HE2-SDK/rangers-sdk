#pragma once

namespace app::player {
    class EffectFootIK : public PlayerEffect {
    public:
        uint64_t unk201;
        uint64_t unk202;
        uint32_t unk203;

        CREATE_FUNC(EffectFootIK, hh::game::GameObject* playerObject, PlayerVisual* playerVisual);

        virtual unsigned int GetNameHash() const override;
        virtual void Update(int64_t a2, float deltaTime) override;
        virtual void UnkFunc3() override;
        virtual void UnkFunc4() override;
    };
}
