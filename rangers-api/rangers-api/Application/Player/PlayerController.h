#pragma once

namespace app::player {
    class MoveCommand;

    class PlayerController : public hh::fnd::ReferencedObject {
    public:
        struct PlayerInfo {
            csl::math::Vector3 playerPosition;
            csl::math::Quaternion playerRotation;
            csl::math::Vector3 unk5;
            csl::math::Vector3 unk6;
            csl::math::Vector3 playerVelocity;
            uint32_t unk8;
            GOCPlayerKinematicParams::JumpInfo unk1;
            uint32_t flags;

            PlayerInfo();
        };

        hh::fnd::Reference<PlayerCollision> playerCollision;
        csl::ut::MoveArray<MoveCommand*> moveCommandQueue;
        PlayerInfo unk40;
        PlayerInfo unkF0;
        uint8_t byte1A0;
        csl::ut::InplaceMoveArray<void*, 1> unk1A8;
        uint64_t qword1D0;
        MoveCommand* moveCommandQueueBuffer;

        void SendMoveCommand(MoveCommand* moveCommand);
        void UpdateKinematics(GOCPlayerKinematicParams* kinematics);

        CREATE_FUNC(PlayerController, PlayerCollision* playerCollision);
    };
}
