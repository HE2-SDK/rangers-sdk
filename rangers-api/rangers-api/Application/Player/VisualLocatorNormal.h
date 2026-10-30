#pragma once

namespace app::player {
    class VisualLocatorNormal : public VisualLocator {
    public:
        csl::math::Transform transform2;
        float unkTau;
        uint8_t unk101;

        DEFAULT_CREATE_FUNC(VisualLocatorNormal);

        virtual unsigned int GetNameHash() override;
        virtual uint64_t UnkFunc2() override { return 0; }
        virtual void AddCallback(GOCPlayerVisual* gocPlayerVisual) override;
        virtual void UnkFunc5(GOCPlayerVisual* gocPlayerVisual, float a3) override;
    };
}
