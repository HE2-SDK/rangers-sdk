#pragma once

namespace hh::deco {
    class DecoRenderer : public fnd::BaseObject {
    public:
        needle::intrusive_ptr<needle::ShaderObject> shaders[7];

        DecoRenderer(csl::fnd::IAllocator* allocator);
    };

    class DecoManager : public game::GameService {
    public:
        DecoRenderer* renderer;
        fnd::ResReflectionT<heur::rfl::DecoTechParams>* decoTechParams;
        csl::ut::StringMap<int64_t> qword80;
        needle::intrusive_ptr<needle::RenderTarget> qwordA0[4];
        needle::intrusive_ptr<needle::Texture> qwordC0[4];

		virtual void* GetRuntimeTypeInfo() const override;

        GAMESERVICE_CLASS_DECLARATION(DecoManager);
    };
}
