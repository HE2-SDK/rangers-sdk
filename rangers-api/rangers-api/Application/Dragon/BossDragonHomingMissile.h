#pragma once

namespace app {
    class BossDragonHomingMissileInfo : public hh::game::ObjInfo {
    public:
        hh::gfx::ResModel* model;

        virtual void Load() override;
        virtual void Initialize(hh::game::GameManager* gameManager) override;
        virtual const char* GetInfoName() override;

        OBJINFO_CLASS_DECLARATION_BASE(BossDragonHomingMissileInfo);
    };

    class BossDragonHomingMissile : public hh::game::GameObject {
    public:
        struct Description {
            hh::game::GameObject* bossDragon;
            hh::fnd::HFrame* bossOffset;
            hh::fnd::HFrame* playerOffset;
            float radius;
            float speed;
            float maxSpeed;
            float accel;
            float rotForce;
            float unk0;
            float unk1;
            float unk2;
            float straightTime;
            float lifeTime;
            csl::math::Vector3 unk3;

            Description();
        };

        hh::game::GameObject* bossDragon;
        hh::fnd::HFrame* bossOffset;
        hh::fnd::HFrame* playerOffset;
        int64_t qword260;
        hh::fnd::Reference<gfx::ModelNodeContainer> modelNodeContainer;
        hh::eff::EffectHandle hh__eff__effecthandle270;
        float radius;
        float rotForce;
        float dword288;
        float dword28C;
        float dword290;
        float straightTime;
        float lifeTime;
        csl::math::Vector3 csl__math__vector32A0;
        csl::math::Vector3 startPosition;
        csl::math::Quaternion csl__math__quaternion2C0;
        float speed;
        float maxSpeed;
        float accel;
        float dword2DC;
        float dword2E0;
        hh::snd::SoundHandle flySound;
        char byte2E8;
        char byte2E9;
        int64_t qword2F0;
        int64_t qword2F8;
        int64_t qword300;
        int64_t qword308;
        float dword310;
        int64_t qword320;
        int64_t qword328;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;

        void Setup(const Description& desc);

        GAMEOBJECT_CLASS_DECLARATION(BossDragonHomingMissile);
    };
}
