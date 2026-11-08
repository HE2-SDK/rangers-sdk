#pragma once

namespace app::player {
    class StatePluginInWater : public PlayerStatePlugin {
    public:
        class WaterDepthProcess : public hh::fnd::ReferencedObject {
        public:
            virtual void AddCallback(PlayerHsmContext* context) = 0;
            virtual void RemoveCallback(PlayerHsmContext* context) = 0;
            virtual void Update(PlayerHsmContext* context, GOCPlayerKinematicParams::LiquidInfo& liquidInfo, GOCPlayerKinematicParams::LiquidInfo& partialLiquidInfo, float deltaTime) = 0;
        };

        class InWaterStatusProcess : public WaterDepthProcess {
        public:
            bool isDrowning;
            float drowningTimer;

            virtual void AddCallback(PlayerHsmContext* context) override {}
            virtual void RemoveCallback(PlayerHsmContext* context) override {}
            virtual void Update(PlayerHsmContext* context, GOCPlayerKinematicParams::LiquidInfo& liquidInfo, GOCPlayerKinematicParams::LiquidInfo& partialLiquidInfo, float deltaTime) override;
        };

        static constexpr const char* name = "StatePluginInWater";

        GOCPlayerKinematicParams::LiquidInfo liquidInfo;
        csl::ut::MoveArray<hh::fnd::Reference<WaterDepthProcess>> waterDepthProcesses;
        int qword80;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginInWater);
    };
}
