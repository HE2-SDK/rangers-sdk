#pragma once

namespace app::player {
    class SonicContext : public PlayerHsmContext {
    public:
        DEFAULT_CREATE_FUNC(SonicContext);
    };

    class Sonic : public Player {
    public:
        static constexpr size_t stateDescCount = 211;
        static const GOCPlayerHsm::StateDescRef stateDescs[stateDescCount];

        hh::fnd::Reference<SonicContext> context;

        virtual void InitializePlayer() override;
        virtual void DeinitializePlayer() override;

        GAMEOBJECT_CLASS_DECLARATION(Sonic)
    };
}
