#pragma once

namespace app::gfx {
    class InstanceUnit : public hh::game::GameObject {
    public:
        struct Description {
            hh::gfx::ResModel* model;
            hh::fnd::HFrame* frame;
            hh::anim::ResSkeleton* skeleton;
            hh::anim::ResAnimation* animation;
            csl::ut::InplaceMoveArray<hh::fnd::ManagedResource*, 8> modelAnimations;
            bool useCustomName;
            csl::ut::String customName;
            float startFrame;

            Description& operator=(const Description& other);
        };

        Description description;
        csl::ut::MoveArray<hh::fnd::Reference<GeometryInstance>> instances;
        csl::ut::MoveArray<void*> unk310;
        csl::ut::MoveArray<hh::gfx::GOCVisualModel*> gocVisualModels;
        csl::ut::MoveArray<hh::gfx::GOCVisualModelImpl::InstanceTransformInfo> instanceTransforms;
        csl::ut::MoveArray<ModelAnimationPlayer*> modelAnimationPlayers;
        float float390;
        bool byte394;
        bool initialized;
        uint8_t byte396;

		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        GAMEOBJECT_CLASS_DECLARATION(InstanceUnit);
    };
}
