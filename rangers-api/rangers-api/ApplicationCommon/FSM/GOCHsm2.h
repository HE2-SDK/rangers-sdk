#pragma once

namespace app_cmn::fsm {
    class GOCHsm2;
    class GOCHsmContext : public hh::fnd::ReferencedObject {
    public:
        GOCHsm2* gocHsm2;
    };

    class GOCHsm2 : public hh::game::GOComponent {
        hh::ut::StateManager* stateManager;
        hh::ut::HsmBase hsm;
        int currentStateIdx;
        int bottomStateIdx;
        bool unk103; // probably flags as char? 4th bit possibly being BOTTOM_STATE_DIRTY @ 0x140B7F230 (SetBottomStateId)
        uint32_t unk104;
        csl::ut::InplaceMoveArray<void*, 1> unk105;
        app_cmn::fsm::GOCHsmContext* hsmContext;
        uint64_t unk107;
    public:
        struct Description {
            void* states;
            unsigned int stateCount;
            unsigned int stateCapacity;
            int stateStart;
            int32_t updatePriority;
            int32_t messageMask;
            bool preAnimUpdate;
            bool postAnimUpdate;
            bool finalUpdate;
            bool unkFlag;
            app_cmn::fsm::GOCHsmContext* hsmContext;
        };

        GOCHsm2(csl::fnd::IAllocator* pAllocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        void Setup(Description& desc);

        int GetBottomStateIdx() const;
        int GetBottomStateId();
        bool SetBottomStateId(int id);
        inline hh::ut::HsmBase& GetHsm() {
            return hsm;
        }

        GOCOMPONENT_CLASS_DECLARATION(GOCHsm2)
    };

    template<typename T>
    class GOCStateBase : public hh::ut::StateBase<T>{
    public:
        inline GOCStateBase(csl::fnd::IAllocator* allocator) : hh::ut::StateBase<T>{ allocator } {}

        virtual bool DoInit() override { return StateInit(*(T*)this->context); }
        virtual void DoEnter(int previousStateId) override { StateEnter(*(T*)this->context, previousStateId); }
        virtual void DoLeave(int nextStateId) override { StateLeave(*(T*)this->context, nextStateId); }
        virtual bool DoStep(float deltaTime) override { return StateStep(*(T*)this->context, deltaTime); }
        virtual bool DoUpdate(hh::fnd::UpdatingPhase phase, float deltaTime) override { return StateUpdate(*(T*)this->context, phase, deltaTime); }
        virtual bool DoUpdateAsync(hh::fnd::UpdatingPhase phase, float deltaTime) override { return StateUpdateAsync(*(T*)this->context, phase, deltaTime); }

        virtual bool StateStep(T& context, float deltaTime) { return false; }
        virtual bool StateUpdate(T& context, hh::fnd::UpdatingPhase phase, float deltaTime) { return false; }
        virtual bool StateUpdateAsync(T& context, hh::fnd::UpdatingPhase phase, float deltaTime) { return false; }
        virtual bool StateInit(T& context) { return false; }
        virtual void StateEnter(T& context, int previousStateId) {}
        virtual void StateLeave(T& context, int nextStateId) {}
    };
}
