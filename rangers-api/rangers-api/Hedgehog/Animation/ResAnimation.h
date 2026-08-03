#pragma once

namespace hh::anim {
    class ResAnimation : public fnd::ManagedResource {
    public:
        ResAnimation(csl::fnd::IAllocator* allocator);

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;
        virtual float GetDuration() const = 0;
        virtual unsigned int GetFrameLength() = 0;
        virtual unsigned int GetTrackCount() const = 0;
        virtual void GetTrackTransforms(float unk, csl::ut::MoveArray<csl::math::Transform>& transforms) = 0;
        virtual ResAnimation* CreateMirrorAnimation(csl::fnd::IAllocator* allocator, ResSkeleton* skeleton, ResAnimation* resolvedAnimation) = 0;
        virtual bool IsMirrored() const = 0;
        virtual uint64_t UnkFunc7() = 0;
        virtual bool UnkFunc8() = 0;
        virtual uint64_t UnkFunc9() = 0;
    };
}
