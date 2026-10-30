#pragma once

namespace app::game {
    class GravityManager;

    class GravityPhantomListener {
    public:
        virtual void GP_UnkFunc0(int64_t a2) = 0;
    };

    class MyCharacterRBListener : public hh::physics::CharacterRigidBodyListener {
    public:
        virtual void CRBL_UnkFunc0(int64_t a2) override;
    };

    class GOCGravity : public hh::game::GOComponent, public hh::fnd::HFrameListener {
    public:
        struct GravityPhantom {
            enum class Flags : unsigned char {
                IS_POSITION_SET
            };

            GravityManager* gravityManager;
            csl::ut::Bitset<Flags> flags;
            uint8_t byte9;
            uint64_t qword10;
            uint64_t qword18;
            uint64_t qword20;
            uint64_t qword28;
            uint64_t qword30;
            hh::fnd::Handle<hh::game::GOComponent> dword38;
            csl::math::Vector3 position;
            csl::math::Vector3 direction;
            uint32_t dword60;
            GravityPhantomListener* listener;

            GravityPhantom();
            void SetPosition(const csl::math::Vector3& position);
            csl::math::Vector3& GetPosition() const;
        };

        struct SetupInfo {
            uint8_t unk1;
            float magnitude;
            uint64_t unk2;
            uint8_t unk3;
            csl::math::Vector3 direction;
        };

        csl::math::Vector3 direction;
        GravityPhantom gravityPhantom;
        hh::fnd::HFrame* frame;
        bool hasGravityPhantom;

        GOCGravity(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const hh::fnd::HFrame* frame, bool unkParam) override;

        void Setup(const SetupInfo& setupInfo);
        void SetListener(GravityPhantomListener* listener);
        csl::math::Vector3& GetDirection() const;

        GOCOMPONENT_CLASS_DECLARATION(GOCGravity);
    };
}
