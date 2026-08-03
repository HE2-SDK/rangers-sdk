#pragma once

namespace app{
    class TargetPositionHelperListener {
    public:
        virtual int8_t TPHL_UnkFunc0() { return 0; }
    };

    class GOCTargetPositionHelper : public hh::game::GOComponent {
    public:
        struct Target {
            bool isntPlayer; // unsure
            unsigned int nameHash;
            hh::fnd::Handle<hh::game::GameObject> targetObject;
            csl::math::Vector3 position;
            csl::math::Vector3 forwardVector; // or rotation
            csl::math::Vector3 velocity;
            csl::math::Vector3 moveDirection;
        };

        int64_t unk0;
        csl::ut::MoveArray<Target> targets; //unsure
        char unk1;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        csl::math::Vector3 GetPredictedPosition(const char* targetName, float time);
        csl::math::Vector3 GetPredictedPosition(float time); // targetName = PlayerTag9999

        GOCOMPONENT_CLASS_DECLARATION(GOCTargetPositionHelper)
    };
}
