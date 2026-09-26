#pragma once

namespace app::game {
    class PhotoModeService : public hh::game::GameService, public hh::game::GameStepListener, public fnd::AppResourceManagerListener {
    public:
        int64_t qword80;
        int64_t qword88;
        int64_t qword90;
        char byte98;
        csl::ut::InplaceMoveArray<int, 4> qwordA0;
        int dwordD0;
        float dwordD4;
        int dwordDC;
        int byteE0;
        int byteE4;
        float dwordE8;
        float dwordEC;
        float dwordF0;
        float dwordF4;
        char byteF8;
        int dwordFC;
        int dword100;
        int dword104;
        float dword108;
        char byte10C;
        int dword110;
        int dword114;
        int dword118;
        int dword11C;
        int dword120;
        int dword124;
        int dword128;
        int dword12C;
        short word130;
        char byte132;
        csl::math::Vector4 oword140;
        int dword150;
        int dword154;
        int dword158;
        int dword15C;
        int dword160;
        int64_t qword164;
        int dword16C;
        int64_t qword170;
        int64_t qword178;
        int dword180;
        int dword184;
        char byte188;
        int dword18C;
        int dword190;
        int dword194;
        int dword198;
        int dword19C;
        int dword1A0;
        int dword1A4;
        int dword1A8;
        int64_t qword1AC;
        app::Timer app__timer1B4;
        int64_t qword1C0;
        int64_t qword1C8;
        int64_t qword1D0;
        int64_t qword1D8;
        char byte1E0;
        int dword1E4;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
        virtual void ARML_UnkFunc0(int unkParam1) override;

        GAMESERVICE_CLASS_DECLARATION(PhotoModeService);
    };
}
