#pragma once

namespace app::gfx {
    // class LayeredModelAnimationPlayer : public hh::fnd::ReferencedObject {
    // public:
    //     struct Animation {
    //         size_t id;
    //         csl::ut::MoveArray<hh::gfx::ResAnimTexPat*> texPatAnimations;
    //         csl::ut::MoveArray<hh::gfx::ResAnimTexSrt*> texSrtAnimations;
    //         csl::ut::MoveArray<hh::gfx::ResAnimMaterial*> materialAnimations;
    //         csl::ut::MoveArray<hh::gfx::ResAnimVis*> visibilityAnimations;
    //     };

    //     csl::ut::MoveArray<Animation> animations;
    //     hh::fnd::Handle<hh::gfx::GOCVisualModel> model;
    //     uint32_t unk3;

    //     DEFAULT_CREATE_FUNC(LayeredModelAnimationPlayer);

    //     void SetModel(hh::gfx::GOCVisualModel* model);
    //     Animation& GetAnimation(size_t id);
    //     void AddTexPatAnimation(size_t id, hh::gfx::ResAnimTexPat* resource);
    //     void AddTexSrtAnimation(size_t id, hh::gfx::ResAnimTexSrt* resource);
    //     void AddMaterialAnimation(size_t id, hh::gfx::ResAnimMaterial* resource);
    //     void AddVisibilityAnimation(size_t id, hh::gfx::ResAnimVis* resource);
    //     void Initialize();
    //     void SetAnimation(size_t id, bool loop, bool unkParam2);
    //     void SetAnimationOnce(size_t id, bool unkParam2);
    //     void SetAnimationLooping(size_t id, bool unkParam2);
    //     float GetFrame() const;
    //     float GetEndFrame() const;
    //     void SetFrame(float frame);
    //     void SetSpeed(float value);
    //     void ResetSpeed();
    //     bool IsAtEnd() const;
    //     void Play();
    //     void Stop();
    // };

    class ModelAnimationPlayer : public hh::fnd::ReferencedObject {
    public:
        struct Animation {
            size_t id;
            csl::ut::MoveArray<hh::gfx::ResAnimTexPat*> texPatAnimations;
            csl::ut::MoveArray<hh::gfx::ResAnimTexSrt*> texSrtAnimations;
            csl::ut::MoveArray<hh::gfx::ResAnimMaterial*> materialAnimations;
            csl::ut::MoveArray<hh::gfx::ResAnimVis*> visibilityAnimations;
        };

        csl::ut::MoveArray<Animation> animations;
        hh::fnd::Handle<hh::gfx::GOCVisualModel> model;
        uint32_t totalAnimationCount;

        CREATE_FUNC(ModelAnimationPlayer, uint32_t unk3Param);

        void SetModel(hh::gfx::GOCVisualModel* model);
        Animation& GetAnimation(size_t id);
        void AddTexPatAnimation(size_t id, hh::gfx::ResAnimTexPat* resource);
        void AddTexSrtAnimation(size_t id, hh::gfx::ResAnimTexSrt* resource);
        void AddMaterialAnimation(size_t id, hh::gfx::ResAnimMaterial* resource);
        void AddVisibilityAnimation(size_t id, hh::gfx::ResAnimVis* resource);
        void AddAnimation(size_t id, hh::fnd::ManagedResource* resource);
        void ClearAnimations();
        void Initialize();
        void CreateAnimations(size_t id, bool unkParam2);
        void CreateAnimations(size_t id, bool loop, bool unkParam2);
        void SetAnimation(size_t id, bool loop, bool unkParam2);
        void SetAnimationOnce(size_t id, bool unkParam2);
        void SetAnimationLooping(size_t id, bool unkParam2);
        float GetFrame() const;
        float GetEndFrame() const;
        void SetFrame(float frame);
        void SetSpeed(float value);
        void ResetSpeed();
        bool IsAtEnd() const;
        void Play();
        void Stop();
    };
}
