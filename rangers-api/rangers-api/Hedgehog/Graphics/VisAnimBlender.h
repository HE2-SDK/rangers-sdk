#pragma once

namespace hh::gfx {
    struct VisAnimBlenderDesc {
        unsigned int animationCount;
    };

    typedef VisAnimDesc VisAnimControlDesc;

    class VisAnimBlenderBase : public fnd::ReferencedObject {
    public:
        virtual void Initialize(VisAnimBlenderDesc& description) = 0;
        virtual void Deinitialize() = 0;
        virtual void UnkFunc3() = 0;
        virtual VisAnimControlBase* CreateControl(const hh::gfx::VisAnimControlDesc& description) = 0;
        virtual void DestroyAllControl() = 0;
    };

    class GOCVisualModel;
    class VisAnimBlenderHH : public VisAnimBlenderBase {
    public:
        GOCVisualModel* model;
        csl::ut::MoveArray<fnd::Reference<VisAnimControlHH>> animations;
        needle::AnimBlender<needle::AnimVisControl>* needleBlender;

        virtual void Initialize(VisAnimBlenderDesc& description) override;
        virtual void Deinitialize() override;
        virtual void UnkFunc3() override;
        virtual VisAnimControlBase* CreateControl(const hh::gfx::VisAnimControlDesc& description) override;
        virtual void DestroyAllControl() override;

        DEFAULT_CREATE_FUNC(VisAnimBlenderHH);
    };

    class VisAnimBlender : public VisAnimBlenderHH {
    public:
        DEFAULT_CREATE_FUNC(VisAnimBlender);
    };
}
