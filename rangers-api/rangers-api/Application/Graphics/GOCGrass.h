#pragma once

namespace app::gfx{
    class GOCGrass : public hh::game::GOComponent, public hh::fnd::HFrameListener {
    public:
        struct SetupInfo {
            csl::math::Transform unk0;
            uint64_t qword30;
            const char* unk38;
            float dword40;
            uint32_t dword44;
            float dword48;
            uint8_t byte4C;
            uint8_t byte4D;
        };

        uint64_t qword88;
        uint64_t qword90;
        uint64_t qword98;
        csl::math::Transform csl__math__vector4A0;
        csl::math::Transform csl__math__vector4D0;
        uint64_t qword100;
        uint8_t byte108;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const hh::fnd::HFrame* frame, bool unkParam) override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCGrass)
    };
}
