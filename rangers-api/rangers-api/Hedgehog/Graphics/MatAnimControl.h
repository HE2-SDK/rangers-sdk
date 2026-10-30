#pragma once

namespace hh::gfx {
    struct MatAnimDesc {
        ResAnimMaterial* resource;
        uint32_t unk1;
        uint64_t unk2;
        uint8_t unk3;
    };

    class MatAnimControlBase : public fnd::ReferencedObject {
    public:
        virtual void Initialize(MatAnimDesc& description) = 0;
        virtual void Deinitialize() = 0;
        virtual void SetFrame(float frame) = 0;
        virtual void SetLocalTime(float frame) = 0;
        virtual float GetFrame() const = 0;
        virtual float GetLocalTime() const = 0;
        virtual float GetEndFrame() const = 0;
        virtual void SetSpeed(float value) = 0;
        virtual float GetSpeed() const = 0;
        virtual void SetUnk5(float value) = 0;
        virtual float GetUnk5() const = 0;
        virtual void UnkFunc13() = 0;
        virtual float GetEndLocalTime() const = 0;
    };

    class GOCVisualModel;
    class MatAnimControlHH : public MatAnimControlBase {
    public:
        fnd::Handle<game::GOComponent> model;
        fnd::Reference<ResAnimMaterial> resource;
        needle::AnimMaterialControl* control;
        float fps;

        virtual void Initialize(MatAnimDesc& description) override;
        virtual void Deinitialize() override;
        virtual void SetFrame(float frame) override;
        virtual void SetLocalTime(float frame) override;
        virtual float GetFrame() const override;
        virtual float GetLocalTime() const override;
        virtual float GetEndFrame() const override;
        virtual void SetSpeed(float value) override;
        virtual float GetSpeed() const override;
        virtual void SetUnk5(float value) override;
        virtual float GetUnk5() const override;
        virtual void UnkFunc13() override;
        virtual float GetEndLocalTime() const override;

        DEFAULT_CREATE_FUNC(MatAnimControlHH);

        void SetModel(GOCVisualModel* model);
    };

    class MatAnimControl : public MatAnimControlHH {
    public:
        DEFAULT_CREATE_FUNC(MatAnimControl);
    };
}
