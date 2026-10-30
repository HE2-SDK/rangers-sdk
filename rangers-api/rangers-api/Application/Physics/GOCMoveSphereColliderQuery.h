#pragma once

namespace app::physics {
    class GOCMoveSphereColliderQuery : public GOCColliderQuery {
    public:
        struct Description : public GOCColliderQuery::Description {
            float radius;
        };

        csl::math::Vector3 position;
        csl::math::Vector3 velocity;
        float radius;
        uint8_t unk204;

        GOCMoveSphereColliderQuery(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UpdatePhysicsJob(const hh::game::GameStepInfo& gameStepInfo, hh::physics::PhysicsOverlapJob* physicsJob) override;

        void SetRadius(float radius);
        void Setup(const Description& desc);

        GOCOMPONENT_CLASS_DECLARATION(GOCMoveSphereColliderQuery);
    };
}
