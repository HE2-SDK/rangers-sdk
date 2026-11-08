#pragma once

namespace app::player {
    class StatePluginRunning : public PlayerStatePlugin {
    public:
        uint64_t qword28;
        uint32_t qword30;
        float qword34;
        ut::Interpolator<float> interpolator1;
        ut::Interpolator<float> interpolator2;
        uint8_t byte88;
        uint8_t byte89;
        uint32_t dword8C;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginRunning);
    };
}
