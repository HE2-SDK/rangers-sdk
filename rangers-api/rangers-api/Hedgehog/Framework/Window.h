#pragma once

namespace hh::fw {
    class Window : public fnd::ReferencedObject {
    public:
        uint64_t hWnd;
        uint32_t width, height;
        uint32_t posX, posY;
        uint64_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        uint64_t unk7;
        csl::ut::VariableString unk8;
        Window(csl::fnd::IAllocator* allocator);
        virtual uint64_t UnkFunc1() = 0;
        virtual void UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4();
        virtual void UnkFunc5() {}
        virtual void UnkFunc6() {}
        virtual void UnkFunc7() {}
        virtual void UnkFunc8() {}
        virtual bool IsFullscreen() { return false; }
        virtual bool GetMonitorResolution(uint32_t& width, uint32_t& height) { return false; }
        virtual void SetWindowResolutionAndPosition(uint32_t x, uint32_t y, uint32_t width, uint32_t height, bool setRect) {}
        virtual void UnkFunc12() {}
        virtual bool UnkFunc13() { return true; }
        virtual void UnkFunc14() {}
        virtual void UnkFunc15() {}
        virtual bool UnkFunc16() { return false; }
        virtual void UnkFunc17() {}
    };
}
