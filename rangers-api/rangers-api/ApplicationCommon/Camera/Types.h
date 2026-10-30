#pragma once

namespace app_cmn::camera {
    struct FrustumParameter {
        float nearClip;
        float farClip;
        float fov;
        FrustumParameter();
    };

    struct CameraParameter {
        struct Positioning {
            csl::math::Vector3 position;
            csl::math::Vector3 offset;
            csl::math::Vector4 unk3;

            csl::math::Vector3& GetPosition() const;
            csl::math::Vector3 GetFullPosition() const; // Position + Offset
            void SetPosition(csl::math::Vector3& position);
            void SetOffset(const csl::math::Vector3& offset);
        };

        struct Orientation {
            struct Offset {
                float angleX;
                float angleY;
                float distance;
                csl::math::Vector3 targetPosition;
                bool usePosition;
            };
            struct Target {
                csl::math::Vector4 upVector;
                float zRot;  

                void SetZRot(float zRot);
                float GetZRot() const;
            };

            Offset offset;
            Target target;

            void SetTargetPosition(csl::math::Vector3& targetPosition);
            void SetAngleX(float angleX);
            void SetAngleY(float angleY);
            void SetDistance(float distance);
        };

        Positioning positioning;
        Orientation orientation;
        FrustumParameter frustum;

        CameraParameter();
    };

    struct CameraPose {
        csl::math::Vector3 lookAtPos;
        csl::math::Vector3 position;
        csl::math::Vector4 unk3;
        CameraPose();
    };

}
