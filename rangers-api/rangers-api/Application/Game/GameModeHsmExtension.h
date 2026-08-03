#pragma once

namespace app::game{
    class GameModeHsmExtension : public GameModeExtension{
    public:
        static constexpr const char* name = "GameModeHsmExtension";

        struct Description {
            hh::ut::StateDescID* stateDescs;
            int stateDescCount;
            int capacity;
            int initialState;
        };

        hh::ut::HsmBase hsm;
        hh::fnd::Reference<hh::ut::StateManager> stateManager;
        int initialState;
        int newState;
        int unk3;

        virtual unsigned int GetNameHash() override;
        virtual void Initialize() override;
        virtual void Destroy() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
        void Setup(const Description& desc);

        bool ProcessMessage(const hh::fnd::Message& message);
        void SetMaxLeafNodeObjects(int count);
        void ChangeState(int state, int unk3);

        GameModeHsmExtension(csl::fnd::IAllocator* allocator);
    };
}
