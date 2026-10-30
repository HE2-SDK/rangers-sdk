#pragma once

namespace hh::gfx {
    struct MatAnimBlenderDesc {
        unsigned int animationCount;
    };

    typedef MatAnimDesc MatAnimControlDesc;

    class MatAnimBlenderBase : public fnd::ReferencedObject {
    public:
        virtual void Initialize(MatAnimBlenderDesc& description) = 0;
        virtual void Deinitialize() = 0;
        virtual void UnkFunc3() = 0;
        virtual MatAnimControlBase* CreateControl(const hh::gfx::MatAnimControlDesc& description) = 0;
        virtual void DestroyAllControl() = 0;
    };

    class GOCVisualModel;
    class MatAnimBlenderHH : public MatAnimBlenderBase {
    public:
        GOCVisualModel* model;
        csl::ut::MoveArray<fnd::Reference<MatAnimControlHH>> animations;
        needle::AnimBlender<needle::AnimMaterialControl>* needleBlender;

        virtual void Initialize(MatAnimBlenderDesc& description) override;
        virtual void Deinitialize() override;
        virtual void UnkFunc3() override;
        virtual MatAnimControlBase* CreateControl(const hh::gfx::MatAnimControlDesc& description) override;
        virtual void DestroyAllControl() override;

        DEFAULT_CREATE_FUNC(MatAnimBlenderHH);
    };

    class MatAnimBlender : public MatAnimBlenderHH {
    public:
        DEFAULT_CREATE_FUNC(MatAnimBlender);
    };
}
