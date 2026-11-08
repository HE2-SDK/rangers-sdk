#pragma once

namespace app::gfx {
    class GeometryInstance : public hh::fnd::RefByHandleObject, public hh::fnd::HFrameListener {
    public:
        enum Flag : unsigned char {
            UNK0,
            UNK1,
            TRANSFORM_DIRTY,
        };

        typedef hh::fnd::HandleManager<GeometryInstance> HandleManager;

        hh::fnd::HFrame* hFrame;
        csl::math::Transform localTransform;
        csl::math::Transform worldTransform;
        csl::math::Matrix34 worldMatrix;
        float dwordD0;
        csl::ut::Bitset<Flag> flags;

        virtual void HFrameUpdatedCallback(const hh::fnd::HFrame* frame, bool unkParam) override;

        void SetFrame(hh::fnd::HFrame* hFrame);
        void SetUnkFlag();
        void SetTransform(csl::math::Transform& transform);
        void UpdateWorldMatrix();
        const csl::math::Matrix34& GetWorldMatrix() const;

        GeometryInstance(csl::fnd::IAllocator* allocator, int64_t unk);
    };
}
