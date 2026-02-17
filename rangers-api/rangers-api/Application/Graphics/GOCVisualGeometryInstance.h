#pragma once

namespace app::gfx{
    class GOCVisualGeometryInstance : public hh::game::GOComponent {
    public:
        struct Description {
            hh::gfx::ResModel* model;
            hh::fnd::HFrame* frame;
            hh::anim::ResSkeleton* skeleton;
            hh::anim::ResAnimation* animation;
            csl::ut::InplaceMoveArray<hh::fnd::ManagedResource*, 8> modelAnimations;
            csl::math::Transform worldPosition;
            bool useCustomName;
            csl::ut::String customName;
            float startFrame;
        };

        Description description;
        hh::fnd::Handle<GeometryInstance> geometryInstance;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const Description& desc);

        GOCOMPONENT_CLASS_DECLARATION(GOCVisualGeometryInstance)
    };
}
