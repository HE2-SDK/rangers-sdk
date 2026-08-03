#pragma once

namespace hh::physics {
    class GOCMeshCollider : public GOCCollider {
    public:
        struct SetupInfo : public GOCCollider::SetupInfo {
            ResPhysicsMesh* meshResource;

            inline SetupInfo() : GOCCollider::SetupInfo(ColliShape::Type::MESH) {}
        };

        fnd::Reference<ResPhysicsMesh> meshResource;

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void GetShape(ColliShape& shape) const override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCMeshCollider);
    };
}
