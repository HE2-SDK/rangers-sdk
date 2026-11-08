#pragma once

namespace hh::anim {
    class ModelSpaceIk : public CharacterIkListener {
    public:
        csl::ut::InplaceMoveArray<csl::math::Matrix44, 2> unk201;

        void UnkFunc1();
        void UnkFunc2(uint8_t unkParam1, void* unkParam2);
        void UnkFunc3();

        DEFAULT_CREATE_FUNC(ModelSpaceIk);
    };
}
