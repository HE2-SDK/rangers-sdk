#pragma once

namespace app::player {
    class MoveCommand;

    class PlayerController : public hh::fnd::ReferencedObject {
    public:
        struct PlayerInfo {
            csl::math::Vector3 playerPosition;
            csl::math::Quaternion playerRotation;
            csl::math::Vector3 unk5;
            csl::math::Vector3 previousPlayerVelocity;
            csl::math::Vector3 playerVelocity;
            float unk8;
            GOCPlayerKinematicParams::GroundInfo groundInfo;
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
        inline void SendMoveCommand(const MoveCommand& moveCommand) {
            SendMoveCommand((MoveCommand*)&moveCommand);
        }
        void UpdateKinematics(GOCPlayerKinematicParams* kinematics);
        void SetCollisionCache(hh::physics::GOCCollisionCache* gocCollisionCache);

        CREATE_FUNC(PlayerController, PlayerCollision* playerCollision);
    };
}
