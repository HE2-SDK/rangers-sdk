#pragma once

namespace app::player {
    class GOCPlayerKinematicParams : public hh::game::GOComponent {
    public:
        struct GroundInfo {
            enum class Flag : unsigned char {
                HAS_GROUND,
                IS_GROUNDED,
            };

            csl::math::Vector3 position;
            csl::math::Vector3 groundNormal;
            float altitude;
            uint32_t unk3a; // |= 0x02 - in air; lower bits are filterCategory
            hh::physics::GOCCollider::CollisionInfo collisionInfo;
            hh::fnd::Handle<hh::physics::GOCCollider> collider;
            int unk6; //changes when you move
            char unk7;
            csl::ut::Bitset<Flag> flags;

            GroundInfo(); 
            void SetParameters(
                bool isGrounded, 
                char unk7, 
                const csl::math::Vector3& position, 
                const csl::math::Vector3& groundNormal, 
                unsigned int unk3a, 
                unsigned int collisionInfo, 
                hh::fnd::Handle<hh::physics::GOCCollider>& collider,
                unsigned int unk6
            );
            void SetParameters(
                bool isGrounded, 
                char unk7,
                hh::physics::PhysicsQueryResult& physicsQueryResult
            );
            hh::game::GOComponent* GetUnk5() const;
            bool IsGrounded() const;
            bool HasNoGround() const;
            hh::physics::GOCCollider::MaterialType GetMaterialType() const;
            bool GetUnk72();
            void SetAltitude(float altitude);
            void Reset();
            csl::math::Vector3& GetPosition() const;
            csl::math::Vector3& GetGroundNormal() const;
            unsigned int GetCollisionInfo() const;
        };
        struct Unk2 {
            uint32_t unk1;
            hh::fnd::Handle<hh::game::GOComponent> unk1a;
            csl::math::Matrix44 unk2;
            csl::math::Vector4 unk3;
            Unk2();
            void Reset();
        };
        struct Unk3 {
            struct Unk1 {
                uint64_t unk1;
                uint64_t unk2;
                uint64_t unk3;
                uint64_t unk4;
                uint64_t unk5;
                uint64_t unk6;
                uint64_t unk7;
                uint64_t unk8;
                csl::math::Vector4 unk9;
                Unk1();
            };

            uint64_t unk1;
            Unk1 unk2;
            Unk3();
        };
        struct Unk4 {
            csl::math::Vector3 groundNormal;
            csl::math::Vector3 position;
            csl::math::Vector3 unk3;
            uint32_t unk3a;
            hh::physics::GOCCollider::CollisionInfo collisionInfo;
            hh::fnd::Handle<hh::physics::GOCCollider> collider;
            uint32_t unk6b;
            uint8_t unk7;
            Unk4();
        };
        struct Unk5 : Unk4 {
            uint64_t unk101;
            csl::math::Vector4 unk102;
            csl::math::Vector4 unk103;
            csl::math::Matrix44 unk104;
            Unk5();
        };
        struct LiquidInfo {
            csl::math::Vector3 position;
            csl::math::Vector3 upVector; // possibly direction out of the water..?
            hh::physics::GOCCollider::CollisionInfo collisionInfo;
            float distanceToSurface;
            bool underwater;

            LiquidInfo();

            float GetDistanceToSurface() const;
            bool IsUnderwater() const;
            hh::physics::GOCCollider::MaterialType GetMaterialType() const;
            void Reset();
        };
        struct Unk7 {
            csl::ut::MoveArray<csl::math::Vector4> unk1;
            Unk7();
        };

        struct SetupInfo {
            unsigned int unk1;
            csl::math::Vector3 position;
            csl::math::Quaternion rotation;
        };

        csl::math::Transform transform;
        hh::fnd::WorldPosition worldPosition;
        csl::math::Vector3 velocity;
        csl::math::Vector4 unk1;
        csl::math::Vector4 unk2;
        csl::math::Vector4 unk3;
        csl::math::Vector4 unk4;
        csl::math::Vector3 inputDirection;
        csl::math::Vector3 lastInputDirection;
        csl::math::Matrix44 worldTransform;
        uint32_t unk8;
        GroundInfo groundInfo0;
        GroundInfo groundInfo1;
        Unk2 unk11;
        Unk2 unk12;
        Unk3 unk13;
        Unk5 unk14;
        Unk5 unk15;
        LiquidInfo liquidInfo;
        hh::fnd::Reference<GravityController> gravityController;
        csl::math::Vector4 unk18;
        Unk7 unk19;
        uint32_t unk20;
        csl::math::Matrix44 cameraViewMatrix;
        void* unk22;
        void* unk23;
        void* unk24;
        void* unk25;
        uint64_t unk26;
        csl::fnd::IAllocator* allocator;
        uint16_t unk27;
        uint8_t unk28;
        SetupInfo setupInfo;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);

        const csl::math::Transform& GetTransform() const;
        csl::math::Matrix34 GetWorldMatrix() const;
        csl::math::Matrix34 GetWorldTransform() const;
        void SetPosition(const csl::math::Vector3& position);
        void SetRotation(const csl::math::Matrix34& rotation);
        void SetRotation(const csl::math::Quaternion& rotation);
        csl::math::Quaternion& GetRotation() const;
        void SetVelocity(const csl::math::Vector3& velocity);
        void SetGravityScale(float gravityScale);
        csl::math::Vector3 GetForwardTargetPosition() const;
        csl::math::Vector3 GetForwardVector() const;
        GravityController* GetGravityController() const;
        float GetLateralSpeed() const;
        csl::math::Vector3 GetLateralVelocity() const;
        void SetLateralVelocity(const csl::math::Vector3& newVelocity);
        bool IsGrounded() const;
        void SetGroundInfo(const GroundInfo& groundInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerKinematicParams)
    };
}
