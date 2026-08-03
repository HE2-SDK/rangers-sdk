#pragma once

namespace app::gfx {
    class VisualModelCacheManager : public hh::game::GameService {
    public:
        csl::ut::StringMap<int64_t> unk0;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        GAMESERVICE_CLASS_DECLARATION(VisualModelCacheManager)
    };
}
