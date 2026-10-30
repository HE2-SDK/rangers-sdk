#pragma once

namespace app::dv{
    class DvElementCaption : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class LanguageID : unsigned int {
                ENGLISH,
                FRENCH,
                ITALIAN,
                GERMAN,
                SPANISH,
                POLISH,
                PORTUGUESE,
                RUSSIAN,
                JAPANESE,
                CHINESE,
                CHINESE_SIMPLIFIED,
                KOREAN
            };

            enum class Style : unsigned int {
                BOTTOM_POPIN,
                LEFT_SMOOTHFADE,
                MIDDLE_SMOOTHFADE,
                RIGHT_SMOOTHFADE
            };

            char converseName[16];
            LanguageID languageId;
            Style style;
        };

        int overlayJob;

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementCaption)
    };
}
