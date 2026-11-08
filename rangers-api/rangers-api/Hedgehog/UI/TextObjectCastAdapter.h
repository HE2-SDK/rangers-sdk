#pragma once

namespace hh::ui {
    class TextObjectCastAdapter : public fnd::ReferencedObject {
    public:
        class TextImageCastListener : public fnd::ReferencedObject, public UICastListener {
        public:
            TextObject* textObject;
            char byte28;
            bool smoothPos;

            virtual void BeginRenderCastEx(SurfRide::Cast* cast, SurfRide::DrawInterface* drawInterface, void* uiRenderInfo) override;
            virtual void EndRenderCastEx(SurfRide::Cast* cast, SurfRide::DrawInterface* drawInterface, void* uiRenderInfo) override;
            virtual void BeginRenderCast(SurfRide::Cast* cast, SurfRide::DrawInterface* drawInterface, void* uiRenderInfo) override;
            virtual void EndRenderCast(SurfRide::Cast* cast, SurfRide::DrawInterface* drawInterface, void* uiRenderInfo) override;
            virtual int64_t Unk8() override;
            virtual void Unk9(int64_t a2, float a3, float a4) override;
        };

        fnd::Reference<TextObject> textObject;
        fnd::Reference<TextImageCastListener> textImageCastListener;
        fnd::Handle<SurfRideCastHandle> hCast;

        TextObjectCastAdapter(csl::fnd::IAllocator* allocator, TextObject* textObject, fnd::Handle<SurfRideCastHandle>& hCast);

        void SetSmoothPosition(bool enabled);
    };
}
