#pragma once

namespace hh::dv {
    class DiEventManager : public hh::game::GameService, DvSceneControlListener {
    public:
        class ScenePlaybackInfo : public hh::fnd::ReferencedObject{
        public:
            struct Info {
                float curPageStart;
                float curPageEnd;
                int pageIndex;
                char curPageName[32];
                int qword28;
                int qword2C;
                int qword30;
                int qword34;
                int qword38;
                int qword3C;
                int qword40;
                int qword44;
                bool paused;
                char char49;
                char char4A;
                char char4B;
                bool useInfo;
                char dword50;
                short word52;
                char unk7;

                Info();

                bool UseInfo() const;
                void SetPageIndex(int pageIdx);
                void SetPage(const char* page);
            };

            hh::fnd::Handle<DvSceneControl> dvSceneControl;
            Info info;
        };

        struct Description{
            int64_t unk0; //see 0x1401EE7CD
            char unk1;
        };

        csl::ut::MoveArray<ScenePlaybackInfo*> scenePlaybackInfos;
        csl::ut::MoveArray<DvSceneControlListener*> listeners;
        long long unk0;
        int unk1;
        char dvObjectsLayer;
        int unk3;
        int currentScenePlaybackInfoId;
        char unk4;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual bool ReceiveMessage(hh::fnd::Message& message) override;
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
        virtual void OnCutsceneEnd(OnCutsceneEndInfo& info) override;

        virtual void Setup(Description& desc);
        virtual bool UnkFunc1() { return false; }
        virtual bool HasDvSceneControl();
        virtual bool AnyCutscenePlaying();
        virtual void AddListener(DvSceneControlListener* listener);
        virtual void RemoveListener(DvSceneControlListener* listener);
        virtual DvSceneControl* GetDvSceneControl();

        void AddScenePlaybackInfo(const char* sceneName);
        void AddScenePlaybackInfo(const char* sceneName, ScenePlaybackInfo::Info& info);
        void AddScenePlaybackInfo(ResDvScene* resource, ScenePlaybackInfo::Info& info);

        GAMESERVICE_CLASS_DECLARATION(DiEventManager)
    };
}
