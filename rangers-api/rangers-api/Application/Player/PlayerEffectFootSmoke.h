#pragma once

namespace app::player {
    class PlayerEffectFootSmoke : public PlayerEffect {
    public:
        uint32_t unk201;
        uint8_t unk202;
        uint8_t unk203;

        CREATE_FUNC(PlayerEffectFootSmoke, hh::game::GameObject* playerObject, PlayerVisual* playerVisual);

        virtual unsigned int GetNameHash() const override;
        virtual void Update(int64_t a2, float deltaTime) override;
        virtual void UnkFunc3() override;
        virtual void UnkFunc4() override;
    };
}
