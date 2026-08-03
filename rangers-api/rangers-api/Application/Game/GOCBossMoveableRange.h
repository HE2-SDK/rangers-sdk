#pragma once

namespace app::game{
    class GOCBossMoveableRange : public hh::game::GOComponent {
    public:
        enum class DirtyFlag : unsigned int {
            RFL_PARAMS,
            UNK_PARAMS // Updates HFrame
        };
    
        hh::fnd::Reference<hh::fnd::HFrame> objectHFrame;
        csl::math::Transform objectTransform;
        csl::ut::String heightTargetNodeName;
        float heightMoveSpeed;
        float bossToPlayerDistanceMin;
        float bossToPlayerDistanceMax;
        float offsetHeightMin;
        float offsetHeightMax;
        float areaDistanceMin;
        float areaDistanceMax;
        float playerSpawnDistance;
        float playerRespawnDistance;
        float playerRespawnDistance2;
        float unkParams0[3];
        hh::game::GOCTransform* objectGOCTransform;
        float unkParams1[6];
        csl::ut::Bitset<DirtyFlag> dirtyFlags;
        float unkParams1b[5];
        int64_t unk1;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        csl::math::Transform GetObjectTransform() const;
        csl::math::Vector3 GetObjectPosition() const;
        void SetRangeParams(heur::rfl::PlayerMoveableRangeParam* params);
        void SetRangeParams(heur::rfl::PlayerMoveableRangeParam* params, bool updateObjectHFrame);
        void SetRangeParams(bool updateObjectHFrame);
        csl::math::Vector3 GetMoveableRangeTargetPosition(float* outDistanceFactor);
        hh::fnd::HFrame* GetObjectHFrame() const;

        GOCOMPONENT_CLASS_DECLARATION(GOCBossMoveableRange)
    };
}
