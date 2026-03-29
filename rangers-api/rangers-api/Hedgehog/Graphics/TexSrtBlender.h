#pragma once

namespace hh::gfx {
    struct TexSrtBlenderDesc {
        unsigned int animationCount;
    };

    typedef TexSrtDesc TexSrtControlDesc;

    class TexSrtBlenderBase : public fnd::ReferencedObject {
    public:
        virtual void Setup(const TexSrtBlenderDesc& description) = 0;
        virtual void Cleanup() = 0;
        virtual void UnkFunc3() = 0;
        virtual TexSrtControlBase* CreateControl(const hh::gfx::TexSrtControlDesc& description) = 0;
        virtual void DestroyAllControl() = 0;
    };

    class GOCVisualModel;
    class TexSrtBlenderHH : public TexSrtBlenderBase {
    public:
        GOCVisualModel* model;
        csl::ut::MoveArray<fnd::Reference<TexSrtControlHH>> animations;
        needle::AnimBlender<needle::AnimTexSrtControl>* needleBlender;

        virtual void Setup(const TexSrtBlenderDesc& description) override;
        virtual void Cleanup() override;
        virtual void UnkFunc3() override;
        virtual TexSrtControlBase* CreateControl(const hh::gfx::TexSrtControlDesc& description) override;
        virtual void DestroyAllControl() override;

        DEFAULT_CREATE_FUNC(TexSrtBlenderHH);
    };

    class TexSrtBlender : public TexSrtBlenderHH {
    public:
        DEFAULT_CREATE_FUNC(TexSrtBlender);
    };
}
