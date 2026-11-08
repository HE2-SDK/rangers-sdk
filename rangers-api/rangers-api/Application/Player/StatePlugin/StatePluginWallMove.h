#pragma once

namespace app::player {
    class StatePluginWallMove : public PlayerStatePlugin {
    public:
        csl::ut::MoveArray<void*> unk28;
        uint32_t unk48;
        int unk52;
        uint32_t unk56;
        uint8_t unk60;

        virtual unsigned int GetNameHash() const override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        DEFAULT_CREATE_FUNC(StatePluginWallMove);
    };
}
