#pragma once

namespace hh::gfx {
    struct VisAnimDesc {
        ResAnimVis* resource;
        uint32_t unk1;
        uint8_t unk2;
    };

    class VisAnimControlBase : public fnd::ReferencedObject {
    public:
        virtual void Initialize(VisAnimDesc& description) = 0;
        virtual void Deinitialize() = 0;
        virtual void SetFrame(float frame) = 0;
        virtual void SetLocalTime(float frame) = 0;
        virtual float GetFrame() const = 0;
        virtual float GetLocalTime() const = 0;
        virtual float GetEndFrame() const = 0;
        virtual float GetEndLocalTime() const = 0;
        virtual void SetSpeed(float value) = 0;
        virtual float GetSpeed() const = 0;
        virtual void SetUnk5(float value) = 0;
        virtual float GetUnk5() const = 0;
        virtual void UnkFunc13() = 0;
    };

    class GOCVisualModel;
    class VisAnimControlHH : public VisAnimControlBase {
    public:
        fnd::Handle<game::GOComponent> model;
        fnd::Reference<ResAnimVis> resource;
        needle::AnimVisControl* control;
        float fps;

        virtual void Initialize(VisAnimDesc& description) override;
        virtual void Deinitialize() override;
        virtual void SetFrame(float frame) override;
        virtual void SetLocalTime(float frame) override;
        virtual float GetFrame() const override;
        virtual float GetLocalTime() const override;
        virtual float GetEndFrame() const override;
        virtual float GetEndLocalTime() const override;
        virtual void SetSpeed(float value) override;
        virtual float GetSpeed() const override;
        virtual void SetUnk5(float value) override;
        virtual float GetUnk5() const override;
        virtual void UnkFunc13() override;

        DEFAULT_CREATE_FUNC(VisAnimControlHH);

        void SetModel(GOCVisualModel* model);
    };

    class VisAnimControl : public VisAnimControlHH {
    public:
        DEFAULT_CREATE_FUNC(VisAnimControl);
    };
}
