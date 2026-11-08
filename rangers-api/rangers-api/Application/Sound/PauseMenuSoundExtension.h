#pragma once

namespace app::snd {
    class PauseMenuSoundExtension : public SoundDirectorExtension {
    public:
        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;

        DEFAULT_CREATE_FUNC(PauseMenuSoundExtension);
    };
}
