#pragma once

namespace hh::gfx {
    struct TexPatBlenderDesc {
        unsigned int animationCount;
    };

    typedef TexPatDesc TexPatControlDesc;

    class TexPatBlenderBase : public fnd::ReferencedObject {
    public:
        virtual void Initialize(TexPatBlenderDesc& description) = 0;
        virtual void Deinitialize() = 0;
        virtual void UnkFunc3() = 0;
        virtual TexPatControlBase* CreateControl(const hh::gfx::TexPatControlDesc& description) = 0;
        virtual void DestroyAllControl() = 0;
    };

    class GOCVisualModel;
    class TexPatBlenderHH : public TexPatBlenderBase {
    public:
        GOCVisualModel* model;
        csl::ut::MoveArray<fnd::Reference<TexPatControlHH>> animations;
        needle::AnimBlender<needle::AnimTexPatControl>* needleBlender;

        virtual void Initialize(TexPatBlenderDesc& description) override;
        virtual void Deinitialize() override;
        virtual void UnkFunc3() override;
        virtual TexPatControlBase* CreateControl(const hh::gfx::TexPatControlDesc& description) override;
        virtual void DestroyAllControl() override;

        DEFAULT_CREATE_FUNC(TexPatBlenderHH);
    };

    class TexPatBlender : public TexPatBlenderHH {
    public:
        DEFAULT_CREATE_FUNC(TexPatBlender);
    };
}
