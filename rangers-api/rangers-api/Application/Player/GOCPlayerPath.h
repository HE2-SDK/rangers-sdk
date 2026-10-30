#pragma once

namespace app::player {
    class GOCPlayerPath : public hh::game::GOComponent {
    public:
        hh::path::PathEvaluator pathEvaluators[6];

		virtual void* GetRuntimeTypeInfo() const override;

        hh::path::PathEvaluator& GetPathEvaluator(int index) const;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerPath);
    };
}
