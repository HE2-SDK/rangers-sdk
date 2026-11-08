#pragma once
#include <ucsl/resources/light/v2.h>

namespace hh::gfx{
    class GOCPointLight : public hh::game::GOComponent {
    public:
        struct Description{
            unsigned int lightsSize;
            const char* sceneContextManagerName;
        };

        struct Light{
            struct PointProperties{
                float radius;
                float attenuationRadius;
                bool shadowEnabled;
            };

            struct DirectionalProperties{
                float innerConeAngle;
                float outerConeAngle;
                float attenuationRadius;
                bool shadowEnabled;
            };

            csl::math::Vector3 position;
            csl::math::Quaternion rotation;
            float intensity;
            float color[3];
            int idx;
            hh::fnd::HFrame* hFrame;
            ucsl::resources::light::v2::LightType type;
            float computedColor[3];
            csl::math::Position absolutePosition;
            csl::math::Position absoluteRotation;
            union{
                PointProperties pointProps;
                DirectionalProperties directionalProps;
                needle::AnimController* lightAnimController;
            };
        };

        struct LightSetupInfo{
            ucsl::resources::light::v2::LightType type;
            csl::math::Vector3 position;
            float sourceRadius;
            float halfLength;
            float attenuationRadius;
            float innerConeAngle;
            float outerConeAngle;
            hh::fnd::HFrame* hFrame;
            float intensity;
            float color[3];
            bool enableShadow;
        };

        csl::ut::MoveArray<Light> lights;
        hh::fnd::HFrame* hFrame;
        const char* sceneContextManagerName;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        void Setup(Description& desc);
        void SetLightIntensity(unsigned int lightIdx, float intensity);
        void SetLightProperties(unsigned int lightIdx, float* colorARGB, float radius, float rotationMultiplier, float attenuationRadius, float innerConeAngle, float outerConeAngle, bool enableShadow);
        void SetLightProperties(unsigned int lightIdx, float* colorARGB, float radius, float rotationMultiplier, float attenuationRadius, float innerConeAngle, float outerConeAngle, csl::math::Vector3& position, csl::math::Quaternion& rotation);
        bool SetLightAnimTime(unsigned int lightIdx, float time);
        void RemoveLight(unsigned int lightIdx);
        int CreateLight(LightSetupInfo& info);
        int CreateLight(ResMirageLight* resource, hh::fnd::HFrame* hFrame);
        void ClearLights();

        GOCOMPONENT_CLASS_DECLARATION(GOCPointLight)
    };
}
