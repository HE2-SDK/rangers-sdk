#pragma once

namespace app{
    class BossBaseContext;
}

namespace app::game{
    class GOCBossActionSelect;

    class BossActionPluginBase : public hh::fnd::ReferencedObject{
    public:
        struct PossibleAction {
            unsigned int attackId;
            int stateId;
            unsigned int priority;
            float readyTime;
        };

        struct PossibleActionName {
            csl::ut::String stateName;
        private:
            char stateNameAllocation[0x80];
        };

        short unk0;
        short unk1;
        int unk2; // priority?
        app::BossBaseContext* context;

        virtual int GetNameHash() const { return 0; }
        virtual int64_t UnkFunc0() { return 0; }
        virtual void OnAdded() {}
        virtual void OnRemoved() {}
        virtual void Reset() {}
        virtual bool IsInState() { return false; }
        virtual bool UnkFunc5() { return false; }
        virtual bool UpdateState(hh::fnd::UpdatingPhase phase, float deltaTime) { return false; }
        virtual bool UnkFunc7() { return false; }
        virtual bool ProcessMessage(hh::fnd::Message& msg) { return false; }
        virtual bool UnkFunc9(int64_t a2) { return false; }
        virtual bool GetPossibleActions(csl::ut::MoveArray<PossibleAction>& actions) { return false; }
        virtual bool GetPossibleActionNames(csl::ut::MoveArray<PossibleActionName>& actionNames) { return false; }
        virtual bool GetState(int64_t& id, csl::ut::String& name) { return false; }
        virtual bool GetPreparedAction(int64_t* stateId, float* readyTime) { return false;  }
        virtual void ExecuteState(int& stateIdx) {}
        virtual void ExecuteState1(int& state, unsigned char unk0) {}

        inline BossActionPluginBase(csl::fnd::IAllocator* allocator) : ReferencedObject{ allocator, true } {}
    };

    template<typename T>
    class BossActionPlugin : public BossActionPluginBase {

    };

    class BossActionPluginListener {
    public:
        virtual void OnPluginAdded(BossActionPluginBase* plugin) = 0;
        virtual void OnPluginRemoved(BossActionPluginBase* plugin) = 0; // Guessed
    };

    template<typename T>
    class BossActionPluginManager : public hh::fnd::BaseObject{
    public:
        csl::ut::MoveArray<BossActionPluginListener*> listeners;
        T* context;
        csl::ut::MoveArray<hh::fnd::Reference<BossActionPluginBase>> plugins;
        bool paused;

        BossActionPluginBase* GetPlugin(unsigned int nameHash) const {
            for (auto& plugin : plugins)
                if (plugin->GetNameHash() == nameHash)
                    return &plugin;

            return nullptr;
        }
        template<typename X>
        inline X* GetPlugin() const {
            return reinterpret_cast<X*>(GetPlugin(X::name));
        }
        void AddPlugin(BossActionPluginBase* plugin, short priority) {
            plugin->unk2 = priority;
            plugin->OnAdded();
            plugins.push_back({ plugin });
            for (auto* listener : listeners)
                listener->OnPluginAdded(plugin);
        } // unsure on priority
    };

    class BossActionSelectListener {
    public:
        virtual void OnExecuteState(int& state, const char* stateName) {};
        virtual void BASL_UnkFunc1() {};
        virtual void BASL_UnkFunc2() {};
        virtual void ExecuteState1(int& state, unsigned char unk0) {};
        virtual void BASL_UnkFunc4() {};
        virtual void BASL_UnkFunc5() {};
    };

    class GOCBossActionSelect : public hh::game::GOComponent, public BossActionPluginListener {
    public:
        struct Unk0{
            float unk0;
            int unk1;
            int unk2;
            char unk3;
            float unk4;
            int unk5;
            int unk6;
            int unk7;
            int unk8;
            char unk9;
        };

        struct Description{
            app::BossBaseContext* context;
            bool postAnimUpdate;
            bool finalUpdate;
        };

        csl::ut::MoveArray<BossActionSelectListener*> listeners;
        hh::fnd::Reference<app::BossBaseContext> context;
        BossActionPluginManager<app::BossBaseContext>* bossActionPluginMgr;
        int currentState;
        float timeSinceLastChange;
        float timeSinceLastAction;
        csl::ut::InplaceMoveArray<Unk0, 4> unk3;
        int flags;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        virtual void OnPluginAdded(BossActionPluginBase* plugin) override;
        virtual void OnPluginRemoved(BossActionPluginBase* plugin) override;

        void Setup(Description& desc);

        void AddListener(BossActionSelectListener* listener);
        void RemoveListener(BossActionSelectListener* listener);
        void ExecuteState1(unsigned char unk0);

        GOCOMPONENT_CLASS_DECLARATION(GOCBossActionSelect)
    };
}
