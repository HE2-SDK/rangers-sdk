#pragma once

namespace app::player {
    class SonicEffectCyloop : public PlayerEffect {
    public:
        csl::ut::MoveArray<void*> unk201;
        ut::Interpolator<float> unk202;
        ut::Interpolator<float> unk203;
        unsigned int dwordB8;
        float floatBC;
        bool byteC0;

        CREATE_FUNC(SonicEffectCyloop, hh::game::GameObject* playerObject, PlayerVisual* playerVisual, bool byteC0Param);

        virtual unsigned int GetNameHash() const override;
        virtual void Update(int64_t a2, float deltaTime) override;
        virtual void UnkFunc3() override;
        virtual void UnkFunc4() override;
    };
}
