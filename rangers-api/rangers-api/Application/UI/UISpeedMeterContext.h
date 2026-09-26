#pragma once

namespace app::ui {
    class UISpeedMeterContext : public app_cmn::fsm::GOCTinyFsmContext {
    public:
        csl::math::Vector4 oword20;
        hh::ui::LayerController* qword30;
        hh::ui::LayerController* qword38;
        short word40;
        char byte42;
    };
}
