#pragma once
#include <ucsl/resources/anmpxd/v200.h>

namespace hh::anim {
    using ucsl::resources::anmpxd::v200::AnimationData;
    UCSL_NEWTYPE_STRUCT_SIMPLE(AnimationPXDData, ucsl::resources::anmpxd::v200::AnimationPXDData);

    class ResAnimationPxd : public ResAnimation {
    public:
        AnimationPXDData* animPxdData;
        fnd::Reference<PxdAnimation> pxdAnimation;
        uint64_t qword88;
        uint64_t qword90;
        uint64_t qword98;
        uint64_t qwordA0;
        uint64_t qwordA8;
        uint64_t qwordB0;
        uint64_t qwordB8;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAnimationPxd)

        void InitPxdAnimation(AnimationPXDData* animPxdData);

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;
        virtual float GetDuration() const override;
        virtual unsigned int GetFrameLength() override;
        virtual unsigned int GetTrackCount() const override;
        virtual void GetTrackTransforms(float unk, csl::ut::MoveArray<csl::math::Transform>& transforms) override;
        virtual ResAnimationPxd* CreateMirrorAnimation(csl::fnd::IAllocator* allocator, ResSkeleton* skeleton, ResAnimation* resolvedAnimation) override;
        virtual bool IsMirrored() const override;
        virtual uint64_t UnkFunc7() override;
        virtual bool UnkFunc8() override;
        virtual uint64_t UnkFunc9() override;
    };
}
