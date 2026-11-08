#pragma once

namespace app::player {
    class GOCPlayerInformationUpdater : public hh::game::GOComponent {
    public:
        struct SetupInfo {
            hh::fnd::Handle<Player> playerObject;
        };

        hh::fnd::Handle<Player> playerObject;
        uint64_t qword88;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerInformationUpdater)
    };
}
