#pragma once

namespace app::game {
    class CheckBarrier : public app_cmn::game::MoveController {
    public:
        static const char* name; // Used for getting the controller, because strcmp is too expensive for ST..

        struct UnkStr {
            hh::fnd::Reference<hh::physics::PhysicsRaycastJob> physicsRaycastJob;
            csl::math::Vector4 oword10;
            csl::math::Vector3 distanceToRecognizeObstacle;
            float heightToRecognizeAsCliff;
            float dword34;
            int dword38;
            short word3C;
            char byte3E;
            char byte3F;
            char byte40;

            UnkStr();
        };

        struct Description {
            char byte0;
            char byte1;
            csl::math::Vector4 oword10;
            csl::math::Vector3 distanceToRecognizeObstacle;
            float heightToRecognizeAsCliff;
            float dword34;
            char byte38;
        };
        
        UnkStr unkStr20;
        hh::game::GOCTransform* gocTransform;
        char byte78;
        char byte79;

        CheckBarrier();

        virtual const char* GetName() override;
        virtual void Update(const hh::fnd::SUpdateInfo& updateInfo) override;

        void Setup(const Description& desc);
    };
}
