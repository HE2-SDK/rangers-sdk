#pragma once

namespace app::player {
    class PlayerHsmListener {
    public:
        virtual void PlayerHsmInitialized(GOCPlayerHsm* gocPlayerHsm, int initialStateId) {}
        virtual void PlayerHsmEnteredState(GOCPlayerHsm* gocPlayerHsm, int stateId) {}
        virtual void PlayerHsmUpdated(GOCPlayerHsm* gocPlayerHsm, float deltaTime) {}
    };

    class GOCPlayerHsm : public hh::game::GOComponent {
    public:
        struct StateDescRef {
            uint32_t id;
            const hh::ut::StateDesc* stateDesc;
        };
        struct SetupInfo {
            const StateDescRef* stateDescs;
            unsigned int stateDescCount;
            unsigned int maxStateDescCount;
            uint32_t unk105bConfig;
            PlayerHsmContext* hsmContext;
            bool enablePreAnimUpdates;
            bool enablePostAnimUpdates;
            bool enableFinalUpdates;
        };
        enum class Flag : uint8_t {
            UNK0,
            UPDATE_PREANIM,
            UNK2,
            UNK3,
            STATE_CHANGE_PENDING,
            STATE_CHANGE_RESTART_PENDING,
        };

        void ExecuteStateChange(int stateId);
        void ExecuteStateChangeRestart(int stateId);

    public:
        hh::fnd::Reference<hh::ut::StateManager> stateManager;
        hh::ut::HsmBase hsm;
        hh::fnd::Reference<PlayerHsmContext> hsmContext;
        hh::fnd::Reference<PlayerStateParameter> playerStateParameter;
        hh::fnd::Reference<StatePluginManager<PlayerHsmContext>> statePluginManager;
        int initialState;
        int nextState;
        unsigned int priority;
        csl::ut::Bitset<Flag> flags;
        csl::ut::InplaceMoveArray<PlayerHsmListener*, 1> listeners;
        SetupInfo setupInfo;

        GOCPlayerHsm(csl::fnd::IAllocator* pAllocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        void Setup(const SetupInfo& setupInfo);
        void ChangeToNull();
        void ChangeState(int stateId, unsigned int priority);
        void ChangeStateRestart(int stateId, unsigned int priority);
        int GetCurrentState() const;
        int GetNextState() const;
        void AddParam(StateParameter* param);
        void ChangeBottomState(int state);

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerHsm);
    };
}
