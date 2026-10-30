#pragma once

namespace app::physics {
    class GOCCharacterController2;
}

namespace app::game {
    class MoveCharacterController2 : public app_cmn::game::MoveController {
    public:
        static const char* name;

        physics::GOCCharacterController2* gocCharacterController2;

        virtual const char* GetName() override;
        virtual void Update(const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;

        MoveCharacterController2();

        void Setup(); // Technically, a description struct should be passed in, but the setup func seems to not use it.
    };
}

namespace app::physics {
    class GOCCharacterController2 : public hh::game::GOComponent {
    public:
        struct UnkStr {
            hh::fnd::Reference<hh::physics::GOCHeightFieldCollider> gocHeightFieldCollider;
            int64_t qword8;
            int64_t qword10;
            int64_t qword18;
        };

        enum class MoveSystem : unsigned char {
            STAIRS,
            SLIDE,
            LINEAR,
            SIMPLE
        };

        enum class QueryMode : unsigned char {
            SWEEP,
            RAYCAST,
            RAYCAST_DISK,
            NONE
        };

        struct Description {
            char byteB0;
            MoveSystem moveSystem;
            QueryMode queryMode;
            char byteB3;
            float dwordF0;
            float dwordF4;
            float dwordF8;
            float dwordFC;
            float gravity;
            float dword104;
            float dword10C;
            csl::math::Vector4 gap;
            int dword110;
            int dword130;
            int gocCollisionCacheNameHash;
            char updatePriority;
            hh::fnd::ReferencedObject* qword128;
            hh::physics::GOCHeightFieldCollider* gocHeightFieldCollider;
            int64_t qword158;
            char byte160;
        };

        int dword80;
        csl::math::Vector4 oword90;
        int64_t qwordA0;
        int dwordA8;
        int dwordAC;
        char byteB0;
        MoveSystem moveSystem;
        QueryMode queryMode;
        char byteB3;
        csl::math::Vector4 owordC0;
        csl::math::Quaternion owordD0; // rotation..?
        csl::math::Vector4 owordE0;
        float dwordF0;
        float dwordF4;
        float dwordF8;
        float dwordFC;
        float gravity;
        float dword104;
        int dword108;
        float dword10C;
        int dword110;
        int64_t qword118;
        int dword120;
        int64_t qword128;
        int dword130;
        int gocCollisionCacheNameHash;
        UnkStr unkStr138;
        int64_t qword158;
        char byte160;
        char byte161; // |= 0x01 enabled;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const Description& desc);
        void SetEnabled(bool enabled);

        GOCOMPONENT_CLASS_DECLARATION(GOCCharacterController2);
    };
}
