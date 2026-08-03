#pragma once

namespace app::anim{
    class AnimatorTriggerListenerBase : public hh::fnd::ReferencedObject, public hh::anim::TriggerListener {
    public:
        hh::fnd::Handle<hh::anim::GOCAnimator> gocAnimator;
        csl::ut::MoveArray<int> triggerListenerIds;

        void SetGOCAnimator(hh::anim::GOCAnimator* gocAnimator);
        void AddTriggerListener(const char* name);

        AnimatorTriggerListenerBase(csl::fnd::IAllocator* allocator);
    };

    template<typename T>
    class AnimatorTriggerListener : public AnimatorTriggerListenerBase {
    public:
        T* animator;
        void* unkFunc;
    };
}
