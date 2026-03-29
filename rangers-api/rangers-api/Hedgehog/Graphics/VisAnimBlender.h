#pragma once

namespace hh::gfx {
    struct VisAnimBlenderDesc {
        unsigned int animationCount;
    };

    typedef VisAnimDesc VisAnimControlDesc;

    class VisAnimBlenderBase : public fnd::ReferencedObject {
    public:
        virtual void Setup(const VisAnimBlenderDesc& description) = 0;
        virtual void Cleanup() = 0;
        virtual void UnkFunc3() = 0;
        virtual VisAnimControlBase* CreateControl(const hh::gfx::VisAnimControlDesc& description) = 0;
        virtual void DestroyAllControl() = 0;
    };

    class GOCVisualModel;
    class VisAnimBlenderHH : public VisAnimBlenderBase {
    public:
        GOCVisualModel* model;
        csl::ut::MoveArray<fnd::Reference<VisAnimControlHH>> animations;
        void* needleBlender;

        virtual void Setup(const VisAnimBlenderDesc& description) override;
        virtual void Cleanup() override;
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
