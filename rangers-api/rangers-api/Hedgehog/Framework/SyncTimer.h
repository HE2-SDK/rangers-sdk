#pragma once

namespace hh::fw{
    class SyncTimer : 
        public hh::fnd::BaseObject,
        public csl::fnd::Singleton<SyncTimer>
    {
    public:
        bool updateDeltaTime;
        float maxFps;
        int unk1;
        csl::fnd::Tick tick;
        float threadSleepSeconds; //deltaTime
        float afterSleepDeltaTime;
        float beforeSleepDeltaTime;
        float maxDeltaTime;
        csl::fnd::Tick ticks[32];
        csl::fnd::Tick deltaTick;
        int tickCount; // tickCount is & 0x1F
        float fps;

        static SyncTimer* Init();
        void Sync(bool threadSleep);
        void SetFPS(float fps);
    };
}
