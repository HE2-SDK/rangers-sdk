#pragma once

namespace app::player {
    struct HomingTargetInfo {
        hh::fnd::Handle<hh::physics::GOCCollider> target;
        bool unk2;
        uint16_t unk2a;
        uint32_t unk2b;
        hh::fnd::WorldPosition worldPos;
        uint32_t unk3;
        float radius;
        float height;
        uint32_t unk4;
        csl::math::Vector3 unk5;
        csl::math::Vector3 unk6;
        uint64_t unk7;
        csl::math::Vector3 unk8;
        uint32_t unk9;

        HomingTargetInfo();
        HomingTargetInfo(hh::physics::GOCCollider* target);
        void SetUnk1(const csl::math::Vector3& position, const csl::math::Vector3& normal, float height);
        void SetUnk2(bool unk2Param);
        void SetSize(float radius, float height);
        void SetWorldPosition(const hh::fnd::WorldPosition& position);
    };
}
