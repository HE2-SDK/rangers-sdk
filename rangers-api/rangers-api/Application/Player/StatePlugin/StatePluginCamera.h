#pragma once

namespace app::player {
    class StatePluginCamera : public PlayerStatePlugin {
    public:
        uint64_t qword28;
        uint64_t qword30;
        float qword38;
        float qword3C;
        uint8_t byte40;

        virtual unsigned int GetNameHash() const override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        void SetByte40(bool enabled);

        DEFAULT_CREATE_FUNC(StatePluginCamera);
    };
}
