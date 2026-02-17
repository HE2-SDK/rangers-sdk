#pragma once

namespace app {
    class ObjKnucklesWall : public hh::game::GameObject {
    public:
        enum class IdType {
            NORMAL,
            NOID,
        };

        struct Unk1 {
            csl::math::Vector3 oword290;
            csl::math::Vector3 oword2A0;
            uint64_t qword2B0;
            uint64_t qword2B8;
            uint64_t qword2C0;
            uint16_t word2C8;
            uint8_t byte2CA;
        };

        uint64_t qword248;
        uint64_t qword250;
        uint64_t qword258;
        uint64_t qword260;
        hh::anim::GOCAnimationSimple* gocAnimationSimple;
        uint8_t byte270;
        hh::fnd::Reference<gfx::LayeredModelAnimationPlayer> layeredModelAnimationPlayer;
        uint64_t qword280;
        Unk1 unk290;
        IdType idType;

		static const hh::game::GameObjectClass* GetClass();
        CREATE_FUNC(ObjKnucklesWall, IdType type);

		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;

        void LoadModel();
    };
}
