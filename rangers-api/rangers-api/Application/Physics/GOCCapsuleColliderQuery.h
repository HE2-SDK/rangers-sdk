#pragma once

namespace app::physics {
    class GOCCapsuleColliderQuery : public GOCColliderQuery {
    public:
        struct Description : public GOCColliderQuery::Description {
            float radius;
            float height;
        };

        float radius;
        float height;

        GOCCapsuleColliderQuery(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UnkFunc101(void* unkParam1, void* unkParam2) override;

        void Setup(const Description& desc);

        GOCOMPONENT_CLASS_DECLARATION(GOCCapsuleColliderQuery);
    };
}
