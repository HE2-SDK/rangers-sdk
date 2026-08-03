#pragma once

namespace app::game{
    class ScreenFadeManager : 
        public hh::game::GameService, 
        public hh::game::GameStepListener, 
        public app::fnd::AppResourceManagerListener
    {
    public:
        hh::fnd::Handle<FadeObject> fadeObjH; // high render priority
        hh::fnd::Handle<FadeObject> fadeObjL; // low render priority
        hh::fnd::Handle<hh::game::GameObject> handle2;
        hh::fnd::Handle<hh::game::GameObject> handle3;
        int unk0;
        char unk1;
        csl::ut::String unk2; //[None]

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void ARML_UnkFunc0(int unkParam1) override;
        virtual void ARML_UnkFunc1(int unkParam1) override;

        void Fade(float length);
        void FadeOut(float length, const char* name); // Name goes unused though
        inline void FadeOut(float length) { FadeOut(length, nullptr); }
        bool IsFading(); // Actually should be something like IsDoneFading, as it checks whether the FSM state is the done fade idle
        bool IsFadeOver();// And this checks whether the FSM state is the no fade idle

        GAMESERVICE_CLASS_DECLARATION(ScreenFadeManager)
    };
}
