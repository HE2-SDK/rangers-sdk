#pragma once

namespace app::gfx {
    class LayeredModelAnimationPlayer : public hh::fnd::ReferencedObject {
        hh::gfx::MatAnimBlender* InitMatAnimBlender();
        hh::gfx::MatAnimBlender* InitTexPatAnimBlender();
        hh::gfx::MatAnimBlender* InitTexSrtAnimBlender();
        hh::gfx::MatAnimBlender* InitVisAnimBlender();

    public:
        struct Animation {
            size_t id;
            unsigned int layerId;
            csl::ut::MoveArray<hh::gfx::TexPatControlBase*> texPatAnimations;
            csl::ut::MoveArray<hh::gfx::TexSrtControlBase*> texSrtAnimations;
            csl::ut::MoveArray<hh::gfx::MatAnimControlBase*> materialAnimations;
            csl::ut::MoveArray<hh::gfx::VisAnimControlBase*> visibilityAnimations;
            uint8_t unk2;
        };

        csl::ut::MoveArray<Animation> animations;
        hh::fnd::Handle<hh::gfx::GOCVisualModel> gocVisualModel;
        unsigned int animationCount;

        DEFAULT_CREATE_FUNC(LayeredModelAnimationPlayer);

        void SetModel(hh::gfx::GOCVisualModel* model);
        void ClearModel();
        Animation& GetAnimation(size_t id);
        void AddTexPatAnimation(size_t id, hh::gfx::ResAnimTexPat* resource, bool unkParam1);
        void AddTexSrtAnimation(size_t id, hh::gfx::ResAnimTexSrt* resource, bool unkParam1);
        void AddMaterialAnimation(size_t id, hh::gfx::ResAnimMaterial* resource, bool unkParam1);
        void AddVisibilityAnimation(size_t id, hh::gfx::ResAnimVis* resource, bool unkParam1);
        void AddAnimation(size_t id, hh::fnd::ManagedResource* resource, bool unkParam1);
        void AddMaterialAnimation(size_t id, hh::gfx::ResAnimMaterial* resource, const char* maybeMaterialName, bool unkParam1);
        void AddAnimation(size_t id, hh::fnd::ManagedResource* resource, const char* maybeMaterialName, bool unkParam1);
        void ClearAnimations();
        void Initialize();
        // void SetAnimation(size_t id, bool loop, bool unkParam2);
        // void SetAnimationOnce(size_t id, bool unkParam2);
        // void SetAnimationLooping(size_t id, bool unkParam2);
        float GetFrame() const;
        float GetEndFrame() const;
        float GetFrame(size_t id) const;
        float GetEndFrame(size_t id) const;
        void SetFrame(float frame);
        void SetFrame(size_t id, float frame);
        void SetLayer(size_t id, unsigned int layerId);
        void SetSpeed(float value);
        void ResetSpeed();
        bool IsAtEnd() const;
        bool IsAtEnd(unsigned int layerId) const;
        void Pause(unsigned int layerId);
        void Pause();
        void Play(size_t id);
        void Stop();
    };
}
