#pragma once

namespace app::player {
    class VisualLocatorManager;

    class GravityController : public hh::fnd::ReferencedObject, public game::GravityPhantomListener {
    public:
        game::GOCGravity* gocGravity;
        float dword28;
        float dword2C;
        csl::math::Vector4 oword30;
        csl::math::Vector4 oword40;
        hh::path::PathEvaluator pathEvaluator;
        char flags;

        GravityController(csl::fnd::IAllocator* allocator);

        void SetGOCGravity(game::GOCGravity* gocGravity);

        virtual void GP_UnkFunc0(int64_t a2) override;
    };
}
