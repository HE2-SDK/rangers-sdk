#pragma once

namespace hh::physics {
    class PhysicsWorld;
    class ResHeightField;

    struct ColliShape {
        enum Type : uint8_t {
            SPHERE,
            BOX,
            CAPSULE,
            CYLINDER,
            MESH,
            HEIGHTFIELD,
            SKINNED_MESH
        };

        struct SphereParameters {
            float radius;
        };

        struct BoxParameters {
            csl::math::Vector3 dimensions;
        };

        struct CapsuleParameters {
            float radius;
            float halfHeight;
        };

        struct CylinderParameters {
            float radius;
            float halfHeight;
        };

        struct HeightFieldParameters {
            ResHeightField* resource;
        };

        union ColliShapeParameters {
            SphereParameters sphere;
            BoxParameters box;
            CapsuleParameters capsule;
            CylinderParameters cylinder;
            HeightFieldParameters heightField;

            inline ColliShapeParameters& operator=(const ColliShapeParameters& other) {
                box = other.box;
                return *this;
            }
        };

        Type type;
        ColliShapeParameters parameters;
    };

    class MsgTriggerEnter;
    class MsgTriggerLeave;
    class MsgTriggerStay;
    class GOCColliderListener {
    public:
        virtual ~GOCColliderListener() = default;
        virtual void OnEnter(hh::physics::MsgTriggerEnter& msg) {}
        virtual void OnStay(hh::physics::MsgTriggerStay& msg) {}
        virtual void OnLeave(hh::physics::MsgTriggerLeave& msg) {}
    };

    class GOCCollider : public game::GOComponent, public fnd::HFrame::Listener {
    public:
        enum class OverlapFlag : uint16_t {
            ENTER, //reacts to MsgColliderQueryStart
            LEAVE, //reacts to MsgColliderQueryLeave
            STAY //reacts to MsgColliderQueryStay
        };

        enum class LayerType : int8_t {
            NONE = 0,
            SOLID = 1,
            LIQUID = 2,
            THROUGH = 3,
            CAMERA = 4,
            SOLID_ONEWAY = 5,
            SOLID_THROUGH = 6,
            SOLID_TINY = 7,
            SOLID_DETAIL = 8,
            LEAF = 9,
            LAND = 10,
            RAYBLOCK = 11,
            EVENT = 12,
            RESERVED13 = 13,
            RESERVED14 = 14,
            PLAYER = 15,
            ENEMY = 16,
            ENEMY_BODY = 17,
            GIMMICK = 18,
            DYNAMICS = 19,
            RING = 20,
            CHARACTER_CONTROL = 21,
            PLAYER_ONLY = 22,
            DYNAMICS_THROUGH = 23,
            ENEMY_ONLY = 24,
            SENSOR_PLAYER = 25,
            SENSOR_RING = 26,
            SENSOR_GIMMICK = 27,
            SENSOR_LAND = 28,
            SENSOR_ALL = 29,
            RESERVED30 = 30,
            RESERVED31 = 31,
        };

        struct SetupInfo {
            enum class Flag : uint8_t {
                HAS_POSITION,
                HAS_ROTATION,
                HAS_SCALE,
            };

            ColliShape::Type shapeType;
            uint8_t unk2;
            csl::ut::Bitset<Flag> flags;
            char unk0;
            LayerType layer;
            csl::ut::Bitset<OverlapFlag> overlapFlags;
            uint32_t hitFlags;
            uint32_t unk5;
            uint32_t unk6;
            uint32_t unk7;
            fnd::HFrame* frame2;
            csl::math::Transform transform;
            float unk9;
            float unk10;

            SetupInfo(ColliShape::Type shape);
            void SetPosition(csl::math::Vector3 position);
            void SetRotation(csl::math::Quaternion rotation);
            void SetScale(csl::math::Vector3 scale);
        };

        enum class Flag : uint8_t {
            ENABLED,
            FRAME_DIRTY,
        };

        uint64_t pad; // probably some of the next data is actually one big block that's 16 aligned
        GOCColliderImpl* impl;
        fnd::HFrame* frame;
        fnd::HFrame* frame2;
        fnd::WorldPosition transformedWorldPosition;
        fnd::WorldPosition localWorldPosition;
        csl::math::Vector3 scale;
        ColliShape::Type shapeType;
        uint8_t unk104b;
        /*LayerType*/ char filterCategory;
        csl::ut::Bitset<Flag> flags;
        csl::ut::Bitset<OverlapFlag> overlapFlags;
        uint32_t filterFlags;
        uint32_t unk106b;
        uint32_t unk107;
        PhysicsWorld* physicsWorld;
        csl::ut::InplaceMoveArray<GOCColliderListener*, 1> listeners;
        csl::ut::MoveArray<void*> unk110;
        uint64_t unk111;
        float friction;
        float restitution;

        GOCCollider(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual bool fUnk5() override { return true; }
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
		virtual void SetScale(const csl::math::Vector3& scale);
        virtual void GetShape(ColliShape& shape) const = 0;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;

        void Setup(const SetupInfo& setupInfo);
        void AddListener(GOCColliderListener* listener);
        void RemoveListener(GOCColliderListener* listener);
        void SetEnabled(bool enabled);
        void SetFrame(fnd::HFrame* frame);
        void SetPosition(const csl::math::Vector3& position);
        void SetRotation(const csl::math::Quaternion& rotation);
        void SendEnterMessage(GOCCollider* actor);
        void SendStayMessage(GOCCollider* actor);
        void SendLeaveMessage(GOCCollider* actor);

#ifndef NO_EIGEN_MATH
        inline csl::math::Matrix34 GetWorldTransform() const {
           csl::math::Matrix34 matrix;
           matrix.fromPositionOrientationScale(transformedWorldPosition.m_Position, transformedWorldPosition.m_Rotation, scale);
           return matrix;
        };

        inline csl::math::Matrix34 GetLocalTransform() const {
           csl::math::Matrix34 matrix;
           matrix.fromPositionOrientationScale(localWorldPosition.m_Position, localWorldPosition.m_Rotation, scale);
           return matrix;
        };
#endif

        GOCOMPONENT_CLASS_DECLARATION(GOCCollider);
    };
}
