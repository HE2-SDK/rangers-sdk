#pragma once
#include <ucsl/resources/anmpxd/v200.h>

namespace hh::anim {
    using ucsl::resources::anmpxd::v200::AnimationData;

    class PxdAnimationHints : public fnd::ReferencedObject {
    public:
    };

    class PxdAnimation : public fnd::ReferencedObject {
    public:
        char unk;
        bool hasRootMotionData;
        AnimationData* animData;

        virtual unsigned int GetTrackCount() const = 0;
        virtual void GetTrackInfo(float time, csl::math::Transform& transform, int64_t a4) = 0;
        virtual void GetRootTrackInfo(csl::math::Transform& transform, float time) = 0;
        virtual PxdAnimationHints* GetHints(csl::fnd::IAllocator* allocator) = 0;
    };

    class PxdCompressedAnimationHints : public PxdAnimationHints {
    public:
        csl::ut::MoveArray<short> trackRelated;
    };

    class PxdCompressedAnimation : public PxdAnimation {
    public:
        virtual unsigned int GetTrackCount() const override;
        virtual void GetTrackInfo(float time, csl::math::Transform& transform, int64_t a4) override;
        virtual void GetRootTrackInfo(csl::math::Transform& transform, float time) override;
        virtual PxdAnimationHints* GetHints(csl::fnd::IAllocator* allocator) override;

        PxdCompressedAnimation(csl::fnd::IAllocator* allocator, AnimationData* animData);
    };

    class PxdAclAnimation : public PxdAnimation {
    public:
        class DecompressionContext : public fnd::ReferencedObject {
        public:
            char gap18[0x28];
            char aclContext[0x80];
        };

        fnd::Reference<DecompressionContext> decompressionCtx;
        csl::fnd::Mutex* mutex;

        virtual unsigned int GetTrackCount() const override;
        virtual void GetTrackInfo(float time, csl::math::Transform& transform, int64_t a4) override;
        virtual void GetRootTrackInfo(csl::math::Transform& transform, float time) override;
        virtual PxdAnimationHints* GetHints(csl::fnd::IAllocator* allocator) override;

        PxdAclAnimation(csl::fnd::IAllocator* allocator, AnimationData* animData);
    };
}
