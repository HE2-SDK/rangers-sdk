#pragma once

namespace app::snd {
    class IslandSoundExtension : public SoundDirectorExtension {
    public:
        short word18;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::SUpdateInfo updateInfo) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        DEFAULT_CREATE_FUNC(IslandSoundExtension);
    };
}
