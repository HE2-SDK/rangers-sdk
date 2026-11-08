#pragma once

namespace app {
    class ObjCameraFollow : public TObjCamera<camera::FollowCamera, heur::rfl::ObjCameraFollowSpawner> {
    public:
        virtual void SetupCamera(const heur::rfl::ObjCameraFollowSpawner* spawnerData, unsigned int id) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjCameraFollow)
    };
}
