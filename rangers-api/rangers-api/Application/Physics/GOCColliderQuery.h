#pragma once

namespace app::physics {
    class GOCColliderQuery : public hh::game::GOComponent, public hh::fnd::HFrameListener, public hh::game::GameStepListener {
    public:
        enum class OverlapFlag : uint8_t {
            ENTER, //sends MsgColliderQueryEnter to owner of this goc
            LEAVE, //sends MsgColliderQueryLeave to owner of this goc
            STAY, //sends MsgColliderQueryStay to owner of this goc
        };

        enum class Flag : uint8_t {
            ENABLED,
            HAS_FRAME,
            UNK1 //related to MsgColliderQueryLeave
        };

        struct SetupInfo {
            hh::fnd::HFrame* frame{};
            uint32_t unk2{};
            uint32_t unk3{};
            csl::ut::Bitset<OverlapFlag> overlapFlags{};
            uint64_t unk5{};
            csl::math::Transform worldTransform{};
            uint16_t unk6{};
        };

        hh::physics::PhysicsOverlapJob* physicsJob;
        csl::ut::MoveArray<hh::fnd::Handle<hh::physics::GOCCollider>> overlappedColliders;
        csl::ut::MoveArray<void*> unkA8;
        hh::fnd::HFrame* hFrame;
        csl::math::Transform localTransform;
        csl::math::Transform worldTransform;
        uint8_t byte140;
        uint32_t qword144;
        uint32_t qword148;
        hh::physics::PhysicsWorldBullet* physicsWorld;
        uint64_t qword158;
        csl::ut::Bitset<OverlapFlag> ownerOverlapFlags;
        csl::ut::Bitset<Flag> flags;

        GOCColliderQuery(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        virtual bool UnkFunc101(void* unkParam1, void* unkParam2);
        virtual void HFrameUpdatedCallback(const hh::fnd::HFrame* frame, bool unkParam) override;
		virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
		virtual void UpdateCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        void Setup(const SetupInfo& setupInfo);
        void SetFrame(hh::fnd::HFrame* frame);
        void SetPosition(csl::math::Vector3& position);
        void SetEnabled(bool enabled);

        GOCOMPONENT_CLASS_DECLARATION(GOCColliderQuery);
    };
}