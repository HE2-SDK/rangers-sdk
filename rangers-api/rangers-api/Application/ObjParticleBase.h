#pragma once

namespace app{
    class ObjParticleBase : public hh::game::GameObject {
    public:
        hh::eff::EffectHandle effect;
        hh::snd::SoundHandle sound;
        bool inWorldSpace;
        csl::ut::String effectName;
        float unk3;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        bool InWorldSpace() const;
        void SetInWorldSpace(bool value);
        void Stop(bool imm);
        void Reset(const csl::math::Matrix34& transform, float unk0, float unk1);

        ObjParticleBase(csl::fnd::IAllocator* allocator);
    };

    class ObjParticle : public ObjParticleBase {
    public:
        enum class Flags : unsigned char {
            TRIGGER_MESSAGE,
            ALIVE
        };

        csl::ut::Bitset<Flags> flags;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjParticle);
    };

    class ObjParticleVolume : public ObjParticleBase {
    public:
        int viewportId;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjParticleVolume);
    };

    class ObjParticleExtent : public hh::game::GameObject {
    public:
        enum class Flags : unsigned char {
            ACTIVE
        };
    
        csl::ut::MoveArray<hh::eff::EffectHandle> effects;
        hh::game::GOCTransform* gocTransform;
        float respawnTimer;
        csl::ut::Bitset<Flags> flags;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjParticleExtent);
    };
}
