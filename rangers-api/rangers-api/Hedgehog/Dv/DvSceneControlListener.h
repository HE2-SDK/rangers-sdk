#pragma once

namespace hh::dv{
    class DvSceneControlListenerBase {
    };

    class DvSceneControlListener {
    public:
        struct UnkFunc1Info {
            DvSceneControl* dvSceneControl;
            int appElementId;
            DvNodeBase* nodeElement;
            csl::fnd::IAllocator* allocator;
        };

        struct UnkFunc11Info {
            DvSceneControl* dvSceneControl;
            int unk;
        };

        struct OnCutsceneEndInfo {
            DvSceneControl* dvSceneControl;
            gfnd::ViewportData* viewportData;
        };

        struct OnUpdateInfo {
            DvSceneControl* dvSceneControl;
            int unk;
        };

        virtual bool DSCL_UnkFunc1(UnkFunc1Info& info, void** retElement) { return false; }
        virtual bool DSCL_UnkFunc2(void* unk0, void* unk1) { return false; }
        virtual bool DSCL_UnkFunc3() { return false; }
        virtual void DSCL_UnkFunc4() {}
        virtual void DSCL_UnkFunc5() {}
        virtual void DSCL_UnkFunc6() {}
        virtual void OnCutsceneEnd(OnCutsceneEndInfo& info) {}
        virtual void DSCL_UnkFunc8() {}
        virtual void DSCL_UnkFunc9() {}
        virtual void DSCL_UnkFunc10() {}
        virtual void DSCL_UnkFunc11(UnkFunc11Info info) {}
        virtual void OnUpdateInfo(OnUpdateInfo& info) {}
        virtual bool DSCL_UnkFunc13(void* unk0) { return false; }
        virtual bool DSCL_UnkFunc14() { return false; }
        virtual void DSCL_UnkFunc15() {}
        virtual void DSCL_UnkFunc16() {}
    };
}
