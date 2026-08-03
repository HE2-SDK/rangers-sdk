#pragma once

namespace app::game {
    class StageTerrainObject : public hh::game::GameObject {
    public:
        struct Description {
            csl::ut::MoveArray<hh::physics::ResPhysicsMeshBullet*> btmeshes;
            csl::ut::MoveArray<hh::gfx::ResPointcloud*> pointclouds; //app::physics::ResPointcloudCollision*
            bool isPointcloud;
            bool deleteFallDeadCollision;
            bool deleteAirWallCollision;
        };

        csl::ut::MoveArray<hh::physics::ResPhysicsMeshBullet*> btmeshes;
        csl::ut::MoveArray<hh::gfx::ResPointcloud*> pointclouds;
        csl::ut::MoveArray<hh::physics::ResPhysicsMeshBullet*> mergedMeshes;
        bool isPointcloud;
        bool deleteFallDeadCollision;
        bool deleteAirWallCollision;

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        void Setup(const Description& description);

        GAMEOBJECT_CLASS_DECLARATION(StageTerrainObject);
    };  
}
