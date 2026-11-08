#pragma once

namespace app::camera{
    class BossLockOnCamera : public app_cmn::camera::CameraController {
    public:
        struct Unk0{
            char unk0;
            int unk1;
            int unk2;
            int unk3;
            int unk4;
        };

        enum class EaseType : unsigned char {
            SIN = 2,
            CUBIC = 4,
            QUADRATIC = 6
        };

        struct Description{
            hh::fnd::HFrame* hFrame;
            csl::math::Vector4 unk0;
            char unk1;
        };

        hh::fnd::Reference<hh::fnd::HFrame> hFrame0;
        hh::fnd::Reference<hh::fnd::HFrame> bossHFrame;
        csl::math::Vector3 mainLookOffsetPos;
        hh::fnd::HFrame* hFrame2;
        hh::fnd::HFrame* hFrame3;
        csl::math::Vector3 subLookOffsetPos;
        CameraBoom* camBooms[3];
        int64_t unk1;
        int64_t camDelayBehavior;
        int64_t camInterpBehavior0;
        int64_t camPanBehavior;
        int64_t camInterpBehavior1;
        int64_t camSpringBehavior;
        float unk2[5];
        float easeTime;
        int unk3;
        EaseType easeType0;
        float unk3b[2]; // sublookatoffsetpos.x is stored in [0]
        EaseType easeType1;
        int unk3c[3];
        csl::math::Vector4 unk4;
        csl::math::Vector4 unk5;
        Unk0 unk6[5];
        int unk7[8];
        char unk8;
        int64_t unk9;
        int64_t unk10;
        int unk11;

        virtual const char* GetControllerName() const override;
        virtual void UnkFunc2(int64_t a2) override;
        virtual int64_t UnkFunc3() override;
        virtual void UnkFunc5() override;

        void Setup(Description& desc);

        BossLockOnCamera(csl::fnd::IAllocator* allocator);
    };
}
