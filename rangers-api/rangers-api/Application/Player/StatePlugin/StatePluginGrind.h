#pragma once

namespace app::player {
    class StatePluginGrind : public PlayerStatePlugin {
    public:
        uint64_t qword28;
        uint64_t qword30;
        hh::eff::EffectHandle hh__eff__effecthandle38;
        uint32_t dword48;
        uint8_t byte4C;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginGrind);
    };
}
