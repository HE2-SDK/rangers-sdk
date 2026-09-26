#pragma once

namespace app::physics {
    class GOCSphereColliderQuery : public GOCColliderQuery {
    public:
        struct Description : public GOCColliderQuery::Description {
            float radius;
        };

        float radius;

        GOCSphereColliderQuery(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UpdatePhysicsJob(const hh::game::GameStepInfo& gameStepInfo, hh::physics::PhysicsOverlapJob* physicsJob) override;

        void Setup(const Description& desc);

        GOCOMPONENT_CLASS_DECLARATION(GOCSphereColliderQuery);
    };
}
