#pragma once

namespace app::snd {
    class AmbientSoundExtension : public SoundDirectorExtension {
    public:
        static constexpr const char* name = "AmbientSound";

        struct Unk1 {
            uint32_t unk1;
            hh::snd::SoundHandle soundHandle;
            uint32_t unk2;
        };

        Unk1 unk1[8];
        hh::fnd::Handle<AmbSoundCoordinator> ambientSoundCoordinator;
        csl::ut::VariableString unk2;
        uint64_t unk3;
        uint32_t unk4;

        DEFAULT_CREATE_FUNC(AmbientSoundExtension);
        void SetBgmId(unsigned int id, bool autoRemoveRequest);

        virtual ~AmbientSoundExtension();
        virtual unsigned int GetNameHash() const;
        virtual void AddCallback() {}
        virtual void RemoveCallback();
        virtual void Update(hh::fnd::SUpdateInfo updateInfo);
        virtual bool ProcessMessage(hh::fnd::Message& message);
    };
}
