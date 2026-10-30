#pragma once

namespace app::dv{
    class DvElementQTEAccel : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class Button : unsigned int {
                A,
                B,
                X,
                Y
            };

            Button button;
            float unk1;
            int dword8;
            int dwordC;
            char soundName[64];
        };

        hh::fnd::Reference<hh::game::InputComponent> inputComp;
        int startFrame;
        int unk1;
        void* unk2;
        void* unk3;
        int unk4;
        int unk5;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void OnDataUpdated() override;
        virtual void OnDataDeleted() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementQTEAccel)
    };
}
