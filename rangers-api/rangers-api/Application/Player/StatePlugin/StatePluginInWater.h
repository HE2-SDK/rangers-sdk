#pragma once

namespace app::player {
    class StatePluginInWater : public PlayerStatePlugin {
    public:
        GOCPlayerKinematicParams::Unk6 unk28;
        csl::ut::MoveArray<void*> unk60;
        uint32_t unk80;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginInWater);
    };
}
