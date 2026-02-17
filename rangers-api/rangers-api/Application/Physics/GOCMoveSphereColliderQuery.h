#pragma once

namespace app::physics {
    class GOCMoveSphereColliderQuery : public GOCColliderQuery {
    public:
        struct SetupInfo : GOCColliderQuery::SetupInfo {
            float radius{};
        };

        csl::math::Vector3 position;
        csl::math::Vector3 velocity;
        float radius;
        uint8_t unk204;

        GOCMoveSphereColliderQuery(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UnkFunc101(void* unkParam1, void* unkParam2) override;

        void Setup(const SetupInfo& setupInfo);
        void SetRadius(float radius);

        GOCOMPONENT_CLASS_DECLARATION(GOCMoveSphereColliderQuery);
    };
}
