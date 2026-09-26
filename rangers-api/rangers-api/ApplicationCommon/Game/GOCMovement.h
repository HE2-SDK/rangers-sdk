#pragma once

namespace app_cmn::game{
    class GOCMovement;

    struct MovementTransform{
        csl::math::Vector3 position;
        csl::math::Quaternion rotation;
        csl::math::Vector3 velocity;
        csl::math::Vector3 angularVelocity;
        short unk0;
    };

    class MoveController {
    public:
        enum class Flags : unsigned char {
            UPDATE,
            IS_USED
        };

        GOCMovement* gocMovement;
        csl::ut::Bitset<Flags> flags;
        char unk1;

        virtual const char* GetName();
        virtual void Update(const hh::fnd::SUpdateInfo& updateInfo) {}
        virtual void AddCallback() {}
        virtual void RemoveCallback() {}
        virtual ~MoveController();

        void SetGOC(GOCMovement* goc);
        MovementTransform& GetPrevious() const;
        hh::game::GameObject* GetOwner() const;
        GOCMovement* GetGOCMovement() const;
        bool IsFlagSet(Flags flag) const;
        void FireAddCallbackEx(Flags flag);
        void FireAddCallback();
        void FireRemoveCallbackEx(Flags flag);
        void FireRemoveCallback();

        MoveController();
        MoveController(char unk0);
    };

    class GOCMovement : public hh::game::GOComponent{
    public:
        struct Description{
            bool createCheckIrregularController;
            hh::fnd::UpdatingPhase updatePhase;
            int updatePriority;
            bool updateAsync;
        };
        
        enum class Flags : unsigned char {
            UPDATE,
            UPDATE_GOCTRANSFORM,
            CONTROLLER_ADD_CALLBACK,
            CREATE_CHECKIRREGULAR_CONTROLLER
        };

        csl::ut::MoveArray<MoveController*> controllers;
        MovementTransform prev;
        MovementTransform current;
        csl::ut::InplaceMoveArray<int64_t, 1> unk1;
        csl::ut::Bitset<Flags> flags;
        bool updateAsync;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        virtual void OnMovementGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) {}

        void Setup(Description& desc);
        MoveController* GetController(const char* name);
        void AddController(MoveController* controller);
        MovementTransform& GetPrevious() const;
        bool IsFlagSet(Flags flag) const;
        void AllFireRemoveCallback();
        void FireRemoveCallback(const char* controllerName);
        void AllFireAddCallback();
        void FireAddCallback(const char* controllerName);
        void SetCurrentAngularVelocity(const csl::math::Vector3& angularVelocity);
        void SetCurrentVelocity(const csl::math::Vector3& velocity);

        GOCOMPONENT_CLASS_DECLARATION(GOCMovement)
    };
}
