#pragma once

namespace app::snd {
    class SoundDirector;
    class SoundDirectorExtension : public hh::fnd::BaseObject {
    public:
        SoundDirector* soundDirector;

        SoundDirectorExtension(csl::fnd::IAllocator* allocator);
        virtual ~SoundDirectorExtension();

        virtual unsigned int GetNameHash() const = 0;
        virtual void AddCallback() = 0;
        virtual void RemoveCallback() = 0;
        virtual void Update(hh::fnd::SUpdateInfo updateInfo) {}
        virtual bool ProcessMessage(hh::fnd::Message& message) {} 
    };

    class SoundDirector : public hh::game::GameService, public hh::game::GameStepListener, hh::game::GameManagerListener {
    public:
        struct Unk3 {
            hh::fnd::HandleBase handle;
            char name[32];
            hh::snd::SoundTween tween;
            float unk102;
            float unk103;
            float unk104;
            float unk105;
            uint32_t unk106;
            uint8_t unk107;
            bool unk107b;
            uint8_t unk107c;
            uint8_t unk107d;

            Unk3();
        };

        hh::snd::SoundManagerCri* sndMgrCri;
        uint32_t dword88;
        hh::snd::SoundListenerHandle soundListener;
        Unk3 unkA0[3];
        csl::ut::MoveArray<Unk3> unk1A0;
        csl::ut::MoveArray<void*> unk1C0[2];
        csl::ut::MoveArray<void*> unk200[2];
        hh::fnd::Reference<hh::fnd::ResReflectionT<heur::rfl::SoundCommonParameter>> soundCommonParameter;
        hh::fnd::Reference<hh::fnd::ResReflectionT<heur::rfl::BGMInfoParameter>> bgmInfoParameter;
        hh::fnd::Reference<hh::fnd::ResReflectionT<heur::rfl::AmbSoundParameter>> ambSoundParameter;
        hh::fnd::Reference<hh::fnd::ResReflectionT<heur::rfl::CustomMusicParameter>> customMusicParameter;
        float dword260;
        float qword264;
        uint32_t qword268;
        uint32_t qword26C;
        uint32_t qword270;
        uint8_t byte274;
        csl::ut::MoveArray<SoundDirectorExtension*> extensions;
        int dword298;
    
        struct PlayBgmInfo {
            const char* name;
            uint32_t unk1;
            float unk2a;
            float unk2b;
            float unk2c;
            float unk2d;
            uint32_t unk3;
            uint32_t flags;
            uint8_t unk4;
        };

		virtual void* GetRuntimeTypeInfo() const override;
        bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void UpdateCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
		virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;

        void AddExtension(SoundDirectorExtension* extension);
        void RemoveExtension(SoundDirectorExtension* extension);
        SoundDirectorExtension* GetExtension(unsigned int nameHash);
        void PlayBgm(const PlayBgmInfo& playBgmInfo);
        void PlayBgm(unsigned int staticChannel, const PlayBgmInfo& playBgmInfo);
        hh::snd::SoundHandle GetBgmSoundHandle(int index);
        heur::rfl::SoundCommonParameter* GetSoundCommonParameter() const;
        void TweenVolume(unsigned int category, bool enabled, float fadeTime);
        void UpdateVolumes();
        void SetMasterVolume(unsigned int category, float volume);

        template<typename T>
        T* GetExtension() {
            return static_cast<T*>(GetExtension(csl::ut::HashString(T::name)));
        }

        GAMESERVICE_CLASS_DECLARATION(SoundDirector)
    };
}
