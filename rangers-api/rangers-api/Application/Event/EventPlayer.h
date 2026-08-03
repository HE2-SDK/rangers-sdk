#pragma once

namespace app::evt {
    class EventPlayerListener {
    public:
        virtual void EPL_UnkFunc1() {}
        virtual void EPL_UnkFunc2() {}
        virtual void CutsceneStart(const char* cutsceneName) {}
        virtual void CutsceneEnd(const char* cutsceneName) {}
        virtual void EPL_UnkFunc5() {}
        virtual void EPL_UnkFunc6() {}
        virtual void OnMessage(hh::fnd::Message* msg) {}
        virtual void EPL_UnkFunc8() {}
        virtual void EPL_UnkFunc9() {}
    };

    class EventPlayer;

    struct EventSetupData {
        struct PlayInfo {
            enum class Flag : unsigned int {
                USE_SETUP_TRANSFORM, // uses the position, rotation and scale variables instead of the ones in the file
                NO_UNLOAD,
                CANT_SKIP,           // whetever the cutscene is unskippable or not
                PAUSABLE,
                PAUSE_ENEMIES,
                ENABLE_HUD,          // whetever the cockpit ui will show up
                PROGRESS_TIME,
                CAN_SAVE,
                UNK3,
                UNK4, // related to spawn
                CAPPED_FPS = 14
            };

            char cutsceneName[40];
            char soundName[40];
            csl::math::Transform transform;
            bool suspendWorld;
            float speed;
            csl::ut::Bitset<Flag> playFlags;

            PlayInfo(const char* cutsceneName);

            void SetTransform(csl::math::Transform& transform);
            inline void SetCutsceneName(const char* name){
                memcpy(cutsceneName, name, 40);
            }
            inline void SetSoundName(const char* name){
                memcpy(soundName, name, 40);
            }
        };

        struct CameraInfo {
            float interpolateTimeOnStart;
            float interpolateTimeOnFinish;
            bool lookAtEnabled;
            csl::math::Vector3 lookAtTarget;

            void SetLookAtTarget(csl::math::Vector3& target);
        };

        struct ScenePlaybackInfo {
            hh::dv::DiEventManager::ScenePlaybackInfo::Info scenePlaybackInfo;
            bool usePage;

            void SetPageIndex(int pageIdx);
            void SetPage(const char* page);
        };

        enum class PlayerPositionFlag : unsigned char {
            USE_POSITION,   // set the player position from world position
            USE_ROTATION,   // set the player rotation from world position
            UNK0,           // unknown
        };

        enum class PlayerFlag : unsigned char {
            UNK0, // ObjEvent !playerAfterIdle
            VISIBLE0,
            VISIBLE1,
            VISIBLE2,
            VISIBLE3
        };

        PlayInfo playInfo;
        ScenePlaybackInfo scenePlaybackInfo;
        int unk1;
        int unk2;
        heur::rfl::EventPlayTestParam::StartType playerStartType;
        hh::fnd::WorldPosition playerWorldPos;
        csl::ut::Bitset<PlayerPositionFlag> playerPositionFlags;
        csl::ut::Bitset<PlayerFlag> playerFlags;
        int64_t unk4;
        CameraInfo cameraInfo;

        EventSetupData();

        void Setup(const char* cutsceneName);
        static void GetLevelName(const char* cutsceneName, csl::ut::String& value);
        inline void GetLevelName(csl::ut::String& value) const { return GetLevelName(playInfo.cutsceneName, value); }
    };

    class EventScene : public hh::fnd::BaseObject, hh::dv::DvSceneControlListener {
    public:
        enum class Flags : unsigned int {
            HAS_MOVIE = 0x7,
            HAS_MOVIE_4K = 0x8,
            UNK0 = 0x11,
            MOVIE_PLAYING = 0x12
        };

        EventPlayer* evtPlayer;
        hh::ut::TinyFsm<EventScene, hh::ut::TinyFsmEvent> fsm;
        hh::dv::DiEventManager* diEvtMgr;
        EventSetupData setupData;
        void* resourceCollection;
        hh::fnd::Handle<hh::fmv::MovieHandleObj> movieHandle;
        hh::snd::SoundHandle soundHandle;
        long long unk2;
        float unk3;
        csl::ut::Bitset<Flags> flags;

        EventScene(csl::fnd::IAllocator* allocator, const char* cutsceneName);

        EventSetupData& GetSetupData() const;
        void SetEventPlayer(EventPlayer* evtPlayer);
        void SetMovie(bool playing);
        void SetPlayScene(bool play);
    };

    class EventSceneManager : public hh::fnd::BaseObject {
    public:
        EventPlayer* evtPlayer;
        csl::ut::MoveArray<EventScene*> evtScenes;
        csl::ut::MoveArray<csl::ut::VariableString> cutsceneNames;

        EventScene* GetEventScene(const char* cutsceneName);
        bool HasCutscene(const char* cutsceneName);
        void AddCutscene(const char* cutsceneName, bool addCutsceneName);
    };

    class EventEnvironmentContext;

    class EventEnvironment : public hh::fnd::BaseObject {
    public:
        EventEnvironmentContext* evtEnvCtx;

        virtual int64_t GetID() const { return 0; }
        virtual bool EE_UnkFunc2() { return false; }
        virtual void EE_UnkFunc3() {}
        virtual void EE_UnkFunc4() {}
        virtual void EE_UnkFunc5() {}
        virtual void EE_UnkFunc6() {}
        virtual void EE_UnkFunc7() {}
        virtual void AddCallback() {}
        virtual void RemoveCallback() {}
        virtual void EE_UnkFunc10() {}
        virtual void EE_UnkFunc11() {}
        virtual void EE_UnkFunc12() {}
        virtual void EE_UnkFunc13() {}
        virtual int EE_UnkFunc14() { return 0; }
        virtual void EE_UnkFunc15() {}
        virtual void EE_UnkFunc16() {}

        EventEnvironment(csl::fnd::IAllocator* allocator);

        EventEnvironmentContext* GetContext();
    };

    class EventEnvironmentContext : public hh::fnd::BaseObject {
    public:
        EventPlayer* evtPlayer;
        EventSetupData setupData[2];
        app_cmn::camera::CameraParameter camParam;
        bool isPlaying;

        EventSetupData& GetSetupData() const;
        hh::game::GameManager* GetGameManager() const;
        app_cmn::camera::CameraParameter& GetCameraParameter() const;
    };

    class EventEnvironmentManager : public hh::fnd::BaseObject {
    public:
        EventEnvironmentContext* evtEnvCtx;
        csl::ut::MoveArray<EventEnvironment*> evtEnvs;

        EventEnvironment* GetEnvironmentByHash(unsigned int nameHash) const;
        void AddEnvironment(EventEnvironment* env);
    };

    class EventPlayer : public hh::game::GameService, hh::game::GameStepListener, hh::game::GameManagerListener, hh::dv::DvSceneControlListener {
    public:
        class MyDvSceneControlListener {
        public:
            char id;
            EventPlayer* eventPlayer;

            virtual void* EventPlayerDtor();
            virtual void* GetEventPlayerRuntimeTypeInfo();
            virtual void* EventPlayerProcessMessage();
            virtual void KillDvSceneControl(int64_t a2);
            virtual void UnkFunc0() {};
            virtual void* EventPlayerIsAcceptingMessages();
            virtual void* EventPlayerOnAddedToGame();
            virtual void UnkFunc1() {};
            virtual void UnkFunc2() {};
            virtual void UnkFunc3() {};
            virtual void UnkFunc4() {};
            virtual void UnkFunc5() {};
            virtual void* EventPlayerUnk();
            virtual bool UnkFunc6() { return false; };
            virtual void UnkFunc7() {};
            virtual void UnkFunc8() {};
        };

        enum class Flag : unsigned long long {
            LOADING   =  29,
            PLAYING   =  30,
            UNLOADING =  31,
            UNK0      =  32,
        };

        hh::ut::TinyFsm<EventPlayer, hh::ut::TinyFsmEvent> fsm;
        hh::dv::DiEventManager* diEvtMgr;
        long long unk0;
        MyDvSceneControlListener dvSceneControlListeners[2];
        csl::ut::MoveArray<EventPlayerListener*> listeners;
        EventSceneManager* evtSceneMgr;
        EventEnvironmentManager* evtEnvMgr;
        hh::fnd::Handle<hh::game::GameObject> fadeObject;
        int unk2;
        hh::fnd::Handle<hh::game::GameObject> eventLayerChecker;
        bool unk4;
        int unk5;
        hh::fnd::Handle<hh::game::GameObject> eventQteInputObject;
        csl::ut::Bitset<Flag> flags;

        void AddListener(EventPlayerListener* listener);
        void RemoveListener(EventPlayerListener* listener);
        void PlayEvent(EventSetupData& setupData);
        bool IsPlaying();
        bool IsntPlaying();
        bool UnkFadeObjectFSM();
        void HideObject(hh::fnd::Handle<hh::game::GameObject>& object);
        void SetMovie(const char* movieName, bool playing);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
        virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
        virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
        virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
        virtual bool DSCL_UnkFunc1(UnkFunc1Info& info, void** retElement) override;
        virtual bool DSCL_UnkFunc2(void* unk0, void* unk1) override;
        virtual bool DSCL_UnkFunc3() override;
        virtual void OnCutsceneEnd(OnCutsceneEndInfo& info) override;
        virtual bool DSCL_UnkFunc13(void* unk0) override;
        virtual bool DSCL_UnkFunc14() override;

        bool PauseCutscene();
        bool UnPauseCutscene();
        void SetPlayScene(const char* sceneName, bool play);

        static const void*** appDvElementCreateFuncs[44];

        GAMESERVICE_CLASS_DECLARATION(EventPlayer)
    };
}
