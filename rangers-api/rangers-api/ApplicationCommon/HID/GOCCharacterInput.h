#pragma once

namespace app_cmn::hid {
    template<typename T>
    class CharacterInputHistory : public hh::fnd::ReferencedObject {
    public:
        struct HistoryEntry {
            int dword0;
            T value;
        };

        csl::ut::CircularBuffer<HistoryEntry> history;

        inline CharacterInputHistory(csl::fnd::IAllocator* allocator, int historyLength) : hh::fnd::ReferencedObject{ allocator, true }, history{ historyLength, allocator } { }
        bool CheckHistory(float priorityInputTime, int requiredCount) {
            // TODO: Implement
        }
    };

    class CharacterActionHistory : public CharacterInputHistory<char> {
    public:
        CharacterActionHistory(csl::fnd::IAllocator* allocator, int historyLength);
    };

    class CharacterStickHistory : public CharacterInputHistory<csl::math::Vector2> {
    public:
        CharacterStickHistory(csl::fnd::IAllocator* allocator, int historyLength);
    };

    class GOCCharacterInput : public hh::game::GOComponent {
    public:
        struct Description {
            int viewportId;
            int int4;
            int int8;
            int intC;
            int updatePriority;
            char byte14;
        };

        struct AxisMonitor {
            int axisMonitorIdxPositiveX;
            int axisMonitorIdxNegativeX;
            int axisMonitorIdxPositiveY;
            int axisMonitorIdxNegativeY;
            float stateX;
            float stateY;
            bool active;
        };

        int viewportId;
        csl::math::Matrix44 cameraViewMatrix;
        csl::ut::MoveArray<AxisMonitor> axisMonitors;
        csl::ut::MoveArray<hh::fnd::Reference<CharacterActionHistory>> actionHistory;
        csl::ut::MoveArray<hh::fnd::Reference<CharacterStickHistory>> stickHistory;
        char byte130;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const Description& desc);
        bool CheckActionMonitorHistory(int actionMonitorIndex, float priorityInputTime, int requiredCount);
        void ClearActionMonitorHistory(int actionMonitorIndex);
        void AddActionHistory(int index, int historyLength);
        void AddStickHistory(int index, int historyLength);
        void SetAxisMonitorIndices(int axisMonitorIndex, int positiveX, int negativeX, int positiveY, int negativeY);

        GOCOMPONENT_CLASS_DECLARATION(GOCCharacterInput);
    };
}
