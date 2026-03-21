#pragma once

namespace app::player {
    class StatePluginIK : public PlayerStatePlugin {
    public:
        hh::fnd::Reference<hh::anim::ModelSpaceIk> modelSpaceIk;
        uint64_t qword30;
        uint64_t qword38;
        uint64_t qword40;
        uint64_t qword48;
        uint16_t word50;
        uint8_t byte52;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginIK);
    };
}
