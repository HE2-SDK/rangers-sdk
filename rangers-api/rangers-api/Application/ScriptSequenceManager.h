#pragma once

namespace app{
    class ScriptSequenceManager :
        public hh::game::GameService,
        public hh::game::GameStepListener,
        public save::SaveManagerListener
    {
    public:
        struct Function {
            const char* name;
            void* function;
        };

        csl::ut::MoveArray<hh::fnd::Handle<ScriptSequence>> scriptSequences;
        short unk1;
        int unkHandle0;
        hh::fnd::Handle<ScriptSequence> currentScriptSequence;
        int currentSequence;
        int unk4;
        char currentObjectName[0x40];
        short unk5;
        csl::fnd::Mutex mutex;
        csl::ut::StringMap<Function*> luaFunctions;
        hh::fnd::ResReflectionT<heur::rfl::ScriptParameter>* scriptParams;
        int64_t unk8;
        hh::fnd::ResReflectionT<heur::rfl::TalkEventCameraPresetParameter>* talkEventCameraParams;
        int64_t unk10;
        gfx::FxParamManager* fxParamMgr;
        int64_t unk12;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
        virtual void OnLoad(save::SaveManager* saveMgr) override;

        int GetCurrentSequence();
        const char* GetStageName() const;
        hh::fnd::Handle<ScriptSequence> ExecuteScript(const char* name, hh::fnd::Handle<hh::game::GameObject>& scriptObject, hh::fnd::Handle<hh::game::GameObject>& unk0, bool isEndKill);
        hh::fnd::Handle<ScriptSequence> ExecuteSequence(unsigned int id);

        GAMESERVICE_CLASS_DECLARATION(ScriptSequenceManager)
    };
}
