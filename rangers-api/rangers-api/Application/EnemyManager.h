#pragma once

namespace app{
    class EnemyManager : public hh::game::GameService, public hh::game::GameStepListener {
    public:
        struct MiniBoss {
            csl::math::Vector3 position; // unsure
            bool alive;
            void* spawnerData;
            const char* objectType;
            hh::game::ObjectId objectId;
            char unk1[8];
        };

        struct UnkStr3 {
            char unk0[16];
        };

        struct UnkStr4 {
            char unk0[16];
        };

        csl::ut::InplaceMoveArray<hh::game::GOComponent*, 128> gocEnemy;
        csl::ut::InplaceMoveArray<hh::fnd::Handle<hh::game::GOComponent>, 16> unk1;
        csl::ut::InplaceMoveArray<hh::fnd::Handle<hh::game::GOComponent>, 16> unk2;
        csl::ut::InplaceMoveArray<int32_t, 8> unk3;
        csl::ut::InplaceMoveArray<hh::fnd::Handle<hh::game::GameObject>, 4> activeBlockageVolumes; // related to blockage
        hh::fnd::Handle<hh::game::GameObject> enemySquad;
        csl::math::Transform reachablePlayerTransform;
        csl::fnd::Mutex mutex0;
        csl::fnd::Mutex mutex1;
        csl::fnd::Mutex mutex2;
        int32_t unk7;
        int32_t unk7b;
        int16_t unk8;
        int64_t unk8b;
        csl::ut::InplaceMoveArray<MiniBoss, 16> minibosses;
        csl::ut::InplaceMoveArray<UnkStr3, 16> unk10;
        csl::ut::InplaceMoveArray<UnkStr4, 16> unk11;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;;
        virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void UpdateCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        void LoadMiniBossArray();
        void SetReachablePlayerTransform(const csl::math::Transform& t);
        bool SpawnRings(const char* ringSupplyObjectName);
        bool DespawnRings(const char* ringSupplyObjectName);

        GAMESERVICE_CLASS_DECLARATION(EnemyManager)
    };
}
