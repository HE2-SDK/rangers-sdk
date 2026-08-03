#pragma once

namespace app::level {
    class PlayerInformation : public hh::fnd::BaseObject {
    public:
        struct Unk2 {
            hh::fnd::Handle<hh::fnd::Messenger> unk1;
            uint16_t unk2;
            uint32_t unk2a;
            hh::fnd::WorldPosition worldPos;
            uint64_t unk3;
            uint64_t unk4;
            csl::math::Vector3 unk5;
            csl::math::Vector3 unk6;
            uint64_t unk7;
            csl::math::Vector3 unk8;
            uint32_t unk9;
            Unk2();
        };

        struct Unk3 {
            float unk1;
            float unk2;
        };

        struct Unk4 {
            uint64_t unk1;
            uint64_t unk2;
        };

        std::optional<hh::fnd::Handle<app::player::Player>> playerObject;
        std::optional<player::CharacterIdU8> characterId;
        std::optional<csl::math::Vector3> position;
        std::optional<csl::math::Vector3> vector440;
        std::optional<csl::math::Quaternion> rotation;
        std::optional<float> dword80;
        std::optional<csl::math::Vector3> vector490;
        std::optional<csl::math::Vector3> vector4B0;
        std::optional<csl::math::Vector3> vector4D0;
        std::optional<csl::math::Vector3> vector4F0;
        std::optional<csl::math::Vector3> vector4110;
        std::optional<csl::math::Vector3> vector4130;
        std::optional<csl::math::Vector3> vector4150;
        std::optional<csl::math::Vector3> vector4170;
        std::optional<csl::math::Vector3> vector4190;
        std::optional<csl::math::Vector3> playerUp;
        std::optional<csl::math::Vector3> playerRight;
        std::optional<csl::math::Vector3> playerForward;
        std::optional<csl::math::Vector3> vector4210;
        std::optional<csl::math::Vector3> vector4230;
        std::optional<csl::math::Vector3> vector4250;
        std::optional<csl::math::Vector3> vector4270;
        std::optional<bool> word290;
        std::optional<Unk3> qword294;
        std::optional<Unk3> qword2A0;
        std::optional<uint32_t> boostGaugeCount;
        std::optional<float> stamina;
        std::optional<float> dword2BC;
        std::optional<uint8_t> word2C4;
        std::optional<float> dword2C8;
        std::optional<float> quickCyloopAmount;
        std::optional<uint64_t> qword2D8;
        std::optional<int> dword2E4;
        uint32_t dword2EC;
        uint32_t dword2F0;
        std::optional<csl::math::Vector3> groundNormal;
        std::optional<float> altitude;
        std::optional<csl::math::Vector3> vector4330;
        std::optional<uint32_t> dword350;
        std::optional<uint32_t> dword358;
        uint32_t dword360;
        uint32_t dword364;
        uint32_t dword368;
        uint32_t dword36C;
        uint32_t dword370;
        uint32_t dword374;
        uint32_t dword378;
        uint32_t dword37C;
        uint32_t dword380;
        uint32_t dword384;
        uint32_t dword388;
        uint32_t dword38C;
        uint32_t dword390;
        uint32_t dword394;
        uint64_t qword398;
        uint32_t dword3A0;
        uint32_t dword3A4;
        uint32_t dword3A8;
        uint32_t dword3AC;
        uint32_t dword3B0;
        uint32_t dword3B4;
        uint32_t dword3B8;
        uint32_t dword3BC;
        bool bool3C0;
        bool bool3C1;
        bool bool3C2;
        bool bool3C3;
        std::optional<uint32_t> curRings;
        std::optional<uint32_t> maxRings;
        uint32_t dword3D4;
        uint32_t dword3D8;
        std::optional<Unk2> unk13241;
        std::optional<csl::math::Vector3> neckPosition; // Guessed, doesn't react with animations
        std::optional<Unk3> qword4A0;
        std::optional<uint32_t> dword4AC;
        std::optional<uint8_t> word4B4;
        std::optional<uint32_t> dword4B8;
        std::optional<float> dword4C0;
        std::optional<csl::math::Transform> transform44F0;
        Unk4 qword510[3];

        PlayerInformation(csl::fnd::IAllocator* allocator);
    };
}
