#pragma once

namespace app::enemy {
    class EnemyPostureContext : public hh::fnd::BaseObject {
    public:
        hh::game::GameObject* owner;
        app_cmn::game::GOCMovement* movement;
        hh::game::GOCTransform* transform;

        app_cmn::game::GOCMovement* GetMovement() const;

        EnemyPostureContext(csl::fnd::IAllocator* allocator, hh::game::GameObject* owner);
    };

    class EnemyPosture : public game::PostureBase<EnemyPostureContext> {
    public:
        short unk0;
    };

    class EnemyPostureManager : public hh::fnd::BaseObject {
    public:
        csl::ut::InplaceMoveArray<int64_t, 2> unk0;
        EnemyPostureContext* context;
        hh::game::GameObject* owner;
        hh::fnd::Reference<EnemyPosture> currentPosture;

        virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) = 0;
        virtual void Init() = 0;

        void SetContext(EnemyPostureContext* context);
        void ClearPosture();
        EnemyPosture* GetPosture(unsigned int nameHash) const;
        template<typename T>
        inline T* GetPosture() const {
            return reinterpret_cast<T*>(GetPosture(csl::ut::HashString(T::name)));
        };
        void SetPosture(EnemyPosture* posture) const;

        inline EnemyPostureManager(csl::fnd::IAllocator* allocator, hh::game::GameObject* owner) : hh::fnd::BaseObject{ allocator }, owner{ owner }, unk0{ allocator } {}
    };

    class EnemyPostureMoveManager : public EnemyPostureManager {
    public:
        virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void Init() override;

        EnemyPostureMoveManager(csl::fnd::IAllocator* allocator, hh::game::GameObject* owner);
    };

    class GOCEnemyPosture : public hh::game::GOComponent {
    public:
        struct Description {
            EnemyPostureContext* context;
        };

        EnemyPostureContext* postureContext;
        EnemyPostureManager* postureManager;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const Description& desc);

        GOCOMPONENT_CLASS_DECLARATION(GOCEnemyPosture);
    };
}
