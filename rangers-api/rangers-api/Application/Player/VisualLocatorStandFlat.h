#pragma once

namespace app::player {
    class VisualLocatorStandFlat : public VisualLocator {
    public:
        char byte50;
        int dword54;

        DEFAULT_CREATE_FUNC(VisualLocatorStandFlat);

        virtual unsigned int GetNameHash() override;
        virtual uint64_t UnkFunc2() override { return 0; }
        virtual void AddCallback(GOCPlayerVisual* gocPlayerVisual) override;
        virtual void UnkFunc5(GOCPlayerVisual* gocPlayerVisual, float a3) override;
    };
}
