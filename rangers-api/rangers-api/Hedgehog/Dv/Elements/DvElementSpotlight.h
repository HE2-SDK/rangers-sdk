#pragma once

namespace hh::dv{
    class DvElementSpotlight : public DvElementBase {
    public:
        class SpotlightObject : public game::GameObject {
        public:
            int64_t unk0;
            csl::math::Vector3 position;
            csl::math::Quaternion rotation;
            int32_t r,g,b;
            float attenuationRadius;
            float intensity;
            float radius;
            int64_t unk8;
            int32_t lightIndex;
            int32_t unk10;
            
		    virtual void AddCallback(game::GameManager* gameManager) override;
            void SetVisible(bool enabled);

            GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(SpotlightObject);
        };

        struct Description : DvElementBase::Description {
        public:
            bool curveEnabled;
            csl::math::Position position;
            csl::math::Position finishPosition;
            csl::math::Position rotation;
            unsigned int color[3];
            float range;
            float intensity;
            float falloff;
            float angle;
            float unk1[6];
            float curveData[64];
        };

        Description binaryData;
        fnd::Reference<SpotlightObject> light;
        
        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void SetData(void* data) override;
        virtual void DeleteData() override;
        virtual void UnkUpdate(int currentFrame, csl::math::Transform& transform) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementSpotlight)
    };
}
