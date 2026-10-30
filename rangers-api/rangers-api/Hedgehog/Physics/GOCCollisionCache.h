#pragma once

namespace hh::physics {
    class GOCCollisionCache : public game::GOComponent, public fnd::HFrameListener {
        int64_t qword88; // MSVC...
    public:
        struct Description {
            csl::math::Vector4 owordA0;
            csl::math::Vector3 scale;
            char byte98;

            Description();
        };

        fnd::HFrame* frame;
        char byte98;
        char byte99; // &= 0x01 has frame
        csl::math::Vector4 owordA0;
        csl::math::Vector3 scale;
        csl::math::Vector3 position;
        PhysicsWorld* physicsWorld;

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;

        virtual void OnAddedCallback() {}
        virtual void OnRemovedCallback(GOCEvent event, game::GameObject& ownerGameObject, void* data) {}
        virtual void OnHFrameUpdateCallback() = 0;
        virtual void CC_UnkFunc3() = 0;
        virtual void CC_UnkFunc4() = 0;
        virtual void CC_UnkFunc5() = 0;
        virtual void CC_UnkFunc6() = 0;
        virtual void CC_UnkFunc7() = 0;

        GOCCollisionCache(csl::fnd::IAllocator* allocator);

        void SetFrame(fnd::HFrame* hframe);
        void Setup(const Description& description);

        GOCOMPONENT_CLASS_DECLARATION_INLINE_GETCLASS(GOCCollisionCache);
    };

    class GOCCollisionCacheBullet : public GOCCollisionCache {
    public:
        bullet::Cache cache;

        virtual void OnAddedCallback() override;
        virtual void OnRemovedCallback(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void OnHFrameUpdateCallback() override;
        virtual void CC_UnkFunc3() override;
        virtual void CC_UnkFunc4() override;
        virtual void CC_UnkFunc5() override;
        virtual void CC_UnkFunc6() override;
        virtual void CC_UnkFunc7() override;

        GOCOMPONENT_CLASS_DECLARATION(GOCCollisionCacheBullet);
    };
}
