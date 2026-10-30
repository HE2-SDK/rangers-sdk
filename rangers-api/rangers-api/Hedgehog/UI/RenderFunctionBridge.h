#pragma once

namespace hh::ui {
    template<typename T>
    class RenderFunctionBridge : public gfnd::Renderable {
    public:
        T* object;
        void* renderFunction; // guessed
        int64_t dword60;
        char byte68;
        int dword70;

        virtual void Render(const gfnd::RenderableParameter* renderableParameter) override;
    };
}
