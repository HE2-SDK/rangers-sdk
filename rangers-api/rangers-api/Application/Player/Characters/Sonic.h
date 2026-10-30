#pragma once

namespace app::player {
    class SonicContext : public PlayerHsmContext {
    public:
        virtual void OnSave(save::SaveManager* saveMgr) override;

        SonicContext(csl::fnd::IAllocator* allocator);
    };

    class Sonic : public Player {
    public:
        static constexpr size_t stateDescCount = 211;
        static const GOCPlayerHsm::StateDescRef stateDescs[stateDescCount];
		
		hh::fnd::Reference<SonicContext> sonicContext;

        GAMEOBJECT_CLASS_DECLARATION(Sonic)
    };
}
