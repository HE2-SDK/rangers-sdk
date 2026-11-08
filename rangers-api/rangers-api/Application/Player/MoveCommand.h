#pragma once

namespace app::player {
    class MoveCommand {
    public:
        virtual ~MoveCommand() {};
        virtual MoveCommand* Clone(void* buffer) = 0;
        virtual size_t GetClassSize() = 0;
        virtual unsigned int GetNameHash() = 0;
        virtual int64_t UnkFunc0();
        virtual void UnkFunc1(PlayerController::PlayerInfo& playerInfo, PlayerCollision* playerCollision) = 0;
    };

    class UpdateGroundCommand : public MoveCommand {
    public:
        GravityController* gravityController;
        char byte10;

        virtual MoveCommand* Clone(void* buffer) override;
        virtual size_t GetClassSize() override;
        virtual unsigned int GetNameHash() override;
        virtual void UnkFunc1(PlayerController::PlayerInfo& playerInfo, PlayerCollision* playerCollision) override;

        UpdateGroundCommand(GravityController* gravityController);
    };

    class PushOutCommand : public MoveCommand {
    public:
        GravityController* gravityController;
        char byte10;

        virtual MoveCommand* Clone(void* buffer) override;
        virtual size_t GetClassSize() override;
        virtual unsigned int GetNameHash() override;
        virtual void UnkFunc1(PlayerController::PlayerInfo& playerInfo, PlayerCollision* playerCollision) override;

        PushOutCommand(GravityController* gravityController);
    };

    class MovePlainCommand : public MoveCommand {
    public:
        virtual MoveCommand* Clone(void* buffer) override;
        virtual size_t GetClassSize() override;
        virtual unsigned int GetNameHash() override;
        virtual void UnkFunc1(PlayerController::PlayerInfo& playerInfo, PlayerCollision* playerCollision) override;

        MovePlainCommand();
    };

    class TreadmillCommand : public MoveCommand {
    public:
        hh::path::PathEvaluator* pathEvaluator;
        float dword10;
        float dword14;
        float dword18;
        float dword1C;

        virtual MoveCommand* Clone(void* buffer) override;
        virtual size_t GetClassSize() override;
        virtual unsigned int GetNameHash() override;
        virtual void UnkFunc1(PlayerController::PlayerInfo& playerInfo, PlayerCollision* playerCollision) override;

        TreadmillCommand();
    };

    class TreadmillRevertCommand : public MoveCommand {
    public:
        virtual MoveCommand* Clone(void* buffer) override;
        virtual size_t GetClassSize() override;
        virtual unsigned int GetNameHash() override;
        virtual void UnkFunc1(PlayerController::PlayerInfo& playerInfo, PlayerCollision* playerCollision) override;

        TreadmillRevertCommand();
    };

    class IntegrateMoveCommand : public MoveCommand {
    public:
        GravityController* gravityController;
        float movableMaxSlope;
        float activeLandingSlope;
        float dword18;
        float dword1C;
        int dword20;
        char byte24;
        short flags;

        virtual MoveCommand* Clone(void* buffer) override;
        virtual size_t GetClassSize() override;
        virtual unsigned int GetNameHash() override;
        virtual void UnkFunc1(PlayerController::PlayerInfo& playerInfo, PlayerCollision* playerCollision) override;

        IntegrateMoveCommand(GravityController* gravityController);
    };
}
