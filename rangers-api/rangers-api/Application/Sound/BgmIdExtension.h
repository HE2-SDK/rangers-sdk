#pragma once

namespace app::snd {
    class BgmIdExtension : public SoundDirectorExtension, public app::evt::EventPlayerListener {
    public:
        static constexpr const char* name = "BgmIdExtension";

        struct Unk1 {
            uint32_t dwordA0;
            uint32_t dwordA4;
            uint64_t qwordA8;
        };

        uint64_t qword20;
        uint32_t dword28;
        int qword2C;
        unsigned int qword30;
        uint32_t dword34;
        csl::ut::MoveArray<void*> arr38;
        uint32_t dword58;
        uint64_t qword60;
        uint64_t qword68;
        uint64_t qword70;
        uint64_t qword78;
        uint64_t qword80;
        uint64_t qword88;
        uint64_t qword90;
        uint32_t dword98;
        Unk1 unkA0;
        hh::snd::SoundHandle dwordB0;
        uint32_t qwordB4;
        uint32_t qwordB8;
        csl::ut::MoveArray<void*> arrC0;

        DEFAULT_CREATE_FUNC(BgmIdExtension);
        void SetBgmId(unsigned int id, bool autoRemoveRequest);

        virtual ~BgmIdExtension();
        virtual unsigned int GetNameHash() const override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override;
        virtual void Update(hh::fnd::SUpdateInfo updateInfo) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        virtual void EPL_UnkFunc2() override;
        virtual void CutsceneEnd(const char* cutsceneName) override;
        virtual void EPL_UnkFunc5() override;
        virtual void OnMessage(hh::fnd::Message* msg) override;
    };
}
