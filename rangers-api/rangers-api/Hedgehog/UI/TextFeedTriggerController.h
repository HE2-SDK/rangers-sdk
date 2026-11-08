#pragma once

namespace hh::ui {
    class TextFeedTriggerControllerListener {
    public:
        virtual ~TextFeedTriggerControllerListener();
        virtual void TFTCL_UnkFunc0(int64_t a2) {}
    };

    class TextFeedTriggerController : public fnd::ReferencedObject {
    public:
        fnd::Handle<SurfRideCastHandle> hCast;
        csl::ut::InplaceMoveArray<TextFeedTriggerControllerListener*, 1> listeners;
        char byte48;

        TextFeedTriggerController(csl::fnd::IAllocator* allocator, fnd::Handle<SurfRideCastHandle>& hCast);

        void AddListener(TextFeedTriggerControllerListener* listener);
    };
}
