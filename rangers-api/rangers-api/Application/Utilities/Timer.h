#pragma once

namespace app::ut {
    struct Timer {
        float target;
        float current;

        Timer(float time);
        Timer();

        float GetTarget() const;
        float GetCurrent() const;
        float GetProgress();
        float GetRemaining() const;
        bool IsFinished() const;
        bool IsActive() const;
        void Reset();
        void ResetCurrent();
        void Set(float time);
        bool Add(float time);
    };
}
