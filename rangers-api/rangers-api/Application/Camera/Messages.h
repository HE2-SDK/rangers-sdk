#pragma once

namespace app::camera {
    class MsgMotionCamera : public fnd::AppMessage<MsgMotionCamera> {
    public:
        csl::math::Transform animTransform{};

        MsgMotionCamera() : fnd::AppMessage<MsgMotionCamera>{ hh::fnd::MessageID::MOTION_CAMERA } {}
    };

    class MsgCameraOff : public fnd::AppMessage<MsgCameraOff> {
    public:
        float easeOutTime{ 0.0f };
        unsigned int easeType{ 0 };
        char playerId{ 0 };

        MsgCameraOff() : fnd::AppMessage<MsgCameraOff>{ hh::fnd::MessageID::CAMERA_OFF } {}
    };

    class MsgShakeCameraName : public fnd::AppMessage<MsgShakeCameraName> {
    public:
        const char* cameraShakeName{ nullptr };
        csl::math::Vector3 offset{ 0, 0, 0 };
        char unk0{ 0 };

        MsgShakeCameraName() : fnd::AppMessage<MsgShakeCameraName>{ hh::fnd::MessageID::SHAKE_CAMERA_NAME } {}
    };
}