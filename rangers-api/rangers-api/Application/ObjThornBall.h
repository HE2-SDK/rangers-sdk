#pragma once

namespace app{
    class ObjThornBallInfo : public hh::game::ObjInfo {
    public:
        hh::gfx::ResModel* baseModel;
        hh::gfx::ResModel* amyModel;
        hh::fnd::Reference<hh::fnd::ResReflectionT<heur::rfl::ObjThornBallConfig>> config;
        int64_t unused;

        virtual void Initialize(hh::game::GameManager* gameManager) override;
        virtual const char* GetInfoName() override;

        OBJINFO_CLASS_DECLARATION_INLINE(ObjThornBallInfo)
    };

    class ObjThornBall : public hh::game::GameObject {
    public:
        enum class Type : unsigned int {
            NORMAL,
            CYACTION
        };

        hh::fnd::Reference<hh::fnd::HFrame> localFrame;
        hh::game::GOCTransform* gocTransform;
        hh::gfx::GOCVisualModel* gocVisualModel;
        hh::eff::EffectHandle effect;
        csl::math::Vector3 moveDirection;
        csl::math::Vector3 rollingDirection;
        hh::ut::TinyFsm<ObjThornBall>::State_t intialState;
        int unk9;
        int unk10;
        char unk10b;
        Type type;
        int unk11;
        int unk11b;
        int unk12;
        csl::math::Vector3 releaseVelocity;
        csl::math::Vector3 playerPosition;
        hh::physics::GOCSphereCollider* gocCollider;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjThornBall)
        ObjThornBall(csl::fnd::IAllocator* allocator, Type type);
    };
}
