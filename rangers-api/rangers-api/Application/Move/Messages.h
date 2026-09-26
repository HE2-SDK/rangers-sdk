#pragma once

namespace app::move {
    class MsgMovementFindTarget : public fnd::AppMessage<MsgMovementFindTarget> {
    public:
        MsgMovementFindTarget();
    };
    
    class MsgMovementLeaveGround : public fnd::AppMessage<MsgMovementLeaveGround> {
    public:
        MsgMovementLeaveGround();
    };

    class MsgMovementLostTarget : public fnd::AppMessage<MsgMovementLostTarget> {
    public:
        MsgMovementLostTarget();
    };

    class MsgMovementOnGround : public fnd::AppMessage<MsgMovementOnGround> {
    public:
        MsgMovementOnGround();
    };

    class MsgMovementReachRotateTarget : public fnd::AppMessage<MsgMovementReachRotateTarget> {
    public:
        MsgMovementReachRotateTarget();
    };

    class MsgMovementStop : public fnd::AppMessage<MsgMovementStop> {
    public:
        MsgMovementStop();
    };
}
