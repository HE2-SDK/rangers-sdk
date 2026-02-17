#pragma once

namespace app::gfx {
    class GeometryInstanceManager : public hh::game::GameService {
    public:
        csl::ut::StringMap<hh::fnd::Reference<InstanceUnit>> instanceUnitsByName;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        void AddInstance(InstanceUnit::Description& description, hh::fnd::Handle<GeometryInstance>* instance);
        void CreateInstanceUnit(InstanceUnit::Description& description, hh::fnd::Handle<GeometryInstance>* instance);

        GAMESERVICE_CLASS_DECLARATION(GeometryInstanceManager);
    };
}
