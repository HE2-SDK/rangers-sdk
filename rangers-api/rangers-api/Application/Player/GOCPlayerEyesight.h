#pragma once

namespace app::player{
    class PlayerEyesightComponent : public hh::fnd::ReferencedObject, public hh::physics::GOCColliderListener {
    public:
        hh::fnd::Handle<hh::game::GameObject> owner;
        csl::ut::MoveArray<int64_t> qword28;
        char byte48;
        int64_t qword50;
        int64_t qword58;
        csl::ut::MoveArray<hh::fnd::Handle<hh::physics::GOCCollider>> collidersInSight;
        hh::fnd::Reference<hh::physics::PhysicsRaycastJob> physicsJob;
        hh::fnd::Handle<hh::physics::GOCCollider> collider;
        char word8C;
        bool byte8D;
        char byte8E;

        void SetOwner(hh::game::GameObject* object);
        void SetCollider(hh::physics::GOCCollider* collider);

        PlayerEyesightComponent(csl::fnd::IAllocator* allocator, char unk0);

        virtual void OnAdded() {}
        virtual void OnRemoved() {} // Guessed
        virtual unsigned int GetNameHash() = 0;
        virtual void UnkFunc1() = 0;
        virtual void UnkFunc2() = 0;
        virtual void UnkFunc3() = 0;
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}

        virtual void OnStay(hh::physics::MsgTriggerStay& msg) override;
    };

    class HomingEyesight : public PlayerEyesightComponent {
    public:
        static constexpr const char* name = "HomingEyesight";

        class TargetData : public hh::fnd::ReferencedObject {
        public:
            HomingTargetInfo info;
            csl::math::Vector4 unk0;
            float distance;
            int unk2;
            int unk2b;
            int unk3;
            int unk3b;
            int unk4;
            float unk5;
            bool unk6;
            char unk6b;
            char unk7;

            TargetData(csl::fnd::IAllocator* allocator, hh::physics::GOCCollider* collider);
        };

        struct Description {
            int dword0;
            float dword4;
            float dword8;
            const char* eyesightColliderName;
            char gap18[4];
            bool isCyber;
            hh::fnd::HandleBase hh__fnd__handlebase20;
        };

        hh::ut::TinyFsm<HomingEyesight, hh::ut::TinyFsmEvent> fsm;
        csl::ut::MoveArray<hh::fnd::Reference<TargetData>> targetDatas;
        csl::ut::MoveArray<int64_t> qwordF8;
        float dword118;
        float dword11C;
        float dword120;
        float dword124;
        float dword128;
        float dword12C;
        float dword130;
        int dword134;
        hh::fnd::HandleBase dword138;
        int dword13C;
        int dword140;
        short flags; // 0x08 - isCyber

        HomingEyesight(csl::fnd::IAllocator* allocator);

        void Setup(const Description& desc);
        TargetData* GetTargetDataByTarget(hh::physics::GOCCollider* target);

        virtual void OnAdded() override;
        virtual void OnRemoved() override;
        virtual unsigned int GetNameHash() override;
        virtual void UnkFunc1() override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override;
        virtual void UnkFunc4() override;
        virtual void UnkFunc5() override;
    };

    class GOCPlayerEyesight : public hh::game::GOComponent {
    public:
        csl::ut::MoveArray<hh::fnd::Reference<PlayerEyesightComponent>> components;        

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void AddComponent(PlayerEyesightComponent* comp);
        PlayerEyesightComponent* GetComponent(unsigned int nameHash);
        template<typename T>
        inline T* GetComponent() {
            return static_cast<T*>(GetComponent(T::name));
        }

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerEyesight)
    };
}
