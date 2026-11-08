#pragma once

namespace app::ui {
    class RequestOverlayWindow : public RequestOverlayBegin {
    public:
        RequestOverlayTagReplace tagReplace;
        uint8_t unk101;
        uint8_t unk102;
        csl::ut::String header;
        csl::ut::String text;
        csl::ut::String unk105;
        csl::ut::MoveArray<csl::ut::String> options;
        bool unk107;
        bool unk108;
        bool unk109;
        bool unk110;
        bool unk111;
        bool unk112;
        bool unk113;
        bool unk114;
        bool unk115;
        bool unk116;

        DEFAULT_CREATE_FUNC(RequestOverlayWindow);
    };
}
