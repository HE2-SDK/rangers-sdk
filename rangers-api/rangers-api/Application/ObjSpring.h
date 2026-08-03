#pragma once

namespace app {
    class ObjSpring : public hh::game::GameObject {
    public:
        struct UnkStr {
            hh::fnd::Handle<hh::game::GameObject> owner;
            csl::math::Vector3 unk0;
            csl::math::Vector3 unk1;
            csl::math::Vector3 unk2;
            float speed;
            float outOfControl;
            float unk4b; // keepVelocityDistance / firstSpeed
            int unkFlags;
            int unk5;
            char unkFlags1;

            UnkStr(); // see ObjSpring ctor
            void SetOwner(hh::game::GameObject* owner); // 0x14989E830
        }; 

        enum class Flags : unsigned short {
            IS_HORMING,
            IS_EVENT_ON,
            IS_CYLOOP_ON,
            IS_CYKNUCKLE_ON,
            IS_HORIZON,
            IS_VISIBLE,
            IS_AIRTRICK,
            IS_CONSTRAIN,
            UNK0
        };

        enum class SpringType : unsigned int {
            SPRING_CA0,
            SPRING_EGG,
            SPIDER_SPRING,
            DRAGON_ROAD_SPRING,
            SPRING_CA1,
            BIG_SPRING_CA
        };

        SpringType springType;
        hh::eff::EffectHandle airTrickEffect;
        hh::eff::EffectHandle hiddenObjectEffect;
        hh::eff::EffectHandle unkEffect2;
        int unk1;
        UnkStr unkStr;
        hh::fnd::Reference<hh::gfx::GOCVisualModel> gocVisualModel;
        hh::fnd::Reference<hh::gfx::GOCVisualModel> gocVisualModelFan;
        csl::ut::Bitset<Flags> flags;
        int64_t unk5;
        int64_t unk6;
        hh::fnd::Handle<hh::game::GameObject> cyloopSignObject;
        float rollingParamPhase;
        char unk8;
        float unkTimer;
        csl::math::Vector4 unk10; // related to SPIDER_SPRING

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
        virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjSpring);
    };
}
