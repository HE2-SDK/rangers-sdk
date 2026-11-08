#pragma once
#include <ucsl/resources/density-setting/v11.h>
#include <ucsl/resources/density-pointcloud/v4.h>

namespace hh::needle {
    class DensityContainer : public NeedleRefcountObject {
    public:
        struct UnkStr0 {
            struct UnkStr1{
                int64_t unk0; // 0x143A19418
                hh::needle::Texture* unk1; //hh::needle::ImplDX11::NeedleTextureResourceContainer* 0x143A1AA98
                int64_t unk2; // not mentioned in ctor
            };

            UnkStr1 unk0[5];
            int unk1;
            int unk2;
            int64_t unk3;
            int unk4; // not mentioned in ctor
            int unk5;
            hh::needle::SupportFX::SFXAllocator* unkAllocator;
            int64_t unk6[32];
            int dword190;
            int dword194;
            int dword198;
            int dword19C;
            int dword1A0;
            int dword1A4;
            int dword1A8;
            int dword1AC;
            int dword1B0;
            int dword1B4;
            int dword1B8;
            int dword1BC;
            int dword1C0;
            int dword1C4;
            int dword1C8;
            int dword1CC;
            int dword1D0;
            int dword1D4;
            int dword1D8;
            int dword1DC;
            int dword1E0;
            int dword1E4;
            int dword1E8;
            int dword1EC;
            int dword1F0;
            int dword1F4;
            int dword1F8;
            int dword1FC;
            int dword200;
            int dword204;
            int dword208;
            int dword20C;
            int dword210;
            int dword214;
            int64_t qword218;
            int64_t qword220;
            int64_t qword228;
            int64_t qword230;
            int64_t qword238;
            int64_t qword240;
            int64_t qword248;
            int64_t qword250;
            int64_t qword258;
            int64_t qword260;
            int64_t qword268;
            int64_t qword270;
            int64_t qword278;
            int64_t qword280;
            int64_t qword288;
            int64_t qword290;
            int64_t qword298;
            int64_t qword2A0;
            int64_t qword2A8;
            int64_t qword2B0;
            int64_t qword2B8;
            int64_t qword2C0;
            int64_t qword2C8;
            int64_t qword2D0;
            int64_t qword2D8;
            int64_t qword2E0;
            int64_t qword2E8;
            int64_t qword2F0;
            int64_t qword2F8;
            int64_t qword300;
            int64_t qword308;
            int64_t qword310;

            UnkStr0();
        };

        struct UnkStr1{
            int dword0;
            int64_t qword8;
            int64_t qword10;
            int64_t gap18;
            int64_t qword20;
            int64_t qword28;
            int64_t gap30;
            int64_t qword38;
            int64_t qword40;
            int64_t gap48;
            int dword50;
            int dword54;
            int dword58;
            int dword5C;
            int dword60;
            int dword64;
            int dword68;
            int dword6C;
            int dword70;

            UnkStr1();
        };

        struct UnkStr2{
            int64_t qword0;
            int64_t qword8;
            int64_t gap10;
            int64_t qword18;
            int64_t qword20;
            int64_t gap28;
            int64_t qword30;

            UnkStr2();
        };

        csl::ut::MoveArray<int64_t> unk0;
        csl::ut::MoveArray<int64_t> unk1;
        csl::ut::MoveArray32<ucsl::resources::density_pointcloud::v4::InstanceData> instances; //unsure
        int64_t placementTexStreamCompute; //hh::needle::PlacementTextureStreamingCompute* 0x141D23EC0
        UnkStr0 unkStr0;
        UnkStr1 unkStr1;
        UnkStr2 unkStr2;
        csl::ut::MoveArray<int64_t> unk3;
        int64_t qword460;
        int64_t qword468;
        int64_t qword470;
        int64_t qword478;
        int64_t qword480;
        int64_t qword488;
        int64_t qword490;
        int64_t qword498;
        int64_t qword4A0;
        int64_t qword4A8;
        int64_t qword4B0;
        int64_t qword4B8;
        int64_t qword4C0;
        int64_t qword4C8;
        int64_t qword4D0;
        int64_t qword4D8;
        int64_t qword4E0;
        int64_t qword4E8;
        int64_t qword4F0;
        int64_t qword4F8;
        int64_t qword500;
        hh::needle::NeedleRefcountObject *phh__needle__needlerefcountobject508[3];
        int64_t qword520;
        int64_t qword528;
        int64_t qword530;
        int64_t qword538;
        int64_t qword540;
        int64_t qword548;
        int64_t qword550;
        int64_t qword558;
        int8_t gap560[8];
        int64_t qword568;
        int64_t qword570;
        int64_t qword578;
        int64_t qword580;
        int64_t qword588;
        int64_t qword590;
        int32_t dword598;
        int8_t gap59C[4];
        int64_t qword5A0;
        int64_t qword5A8;
        int32_t dword5B0;
        int8_t gap5B4[4];
        int64_t qword5B8[5];
        ucsl::resources::density_setting::v11::DensitySettingData* densitySettingData;
        csl::ut::MoveArray<int64_t> qword5E8;
        csl::ut::MoveArray<int64_t> qword608;
        float dword628;
        float dword62C;
        int16_t word630;
        int8_t byte632;
        int32_t dword634;
        int8_t gap638[8];
        int64_t qword640;
        int64_t qword648;
        int64_t qword650;
        int64_t qword658;
        int32_t dword660;
        int32_t dword664;
        int32_t dword668;
        int32_t dword66C;
        int32_t dword670;
        int8_t gap674[4];
        int64_t qword678;
        int64_t qword680;
        int64_t qword688;
        hh::needle::NeedleRefcountObject *phh__needle__needlerefcountobject690[3];
        int64_t qword6A8;
        csl::ut::MoveArray<int64_t> qword6B0;
        int32_t dword6D0;
        csl::ut::MoveArray<int64_t> qword6D8;
        int64_t qword6F8;
        int32_t dword700;
        int32_t dword704;
        int16_t word708;
        int8_t gap70A[6];
        csl::ut::MoveArray<int64_t> qword710;
        csl::ut::StringMap<int64_t> qword730;
        int64_t qword750;
        int64_t qword758;
        int8_t gap760[240];
        int64_t qword850;
        int64_t qword858;
        int64_t qword860;
        int64_t qword868;
        int64_t qword870;
        csl::fnd::IAllocator* qword878;
        int32_t dword880;

        DensityContainer(csl::fnd::IAllocator* allocator, int unk0, int unk1);
    };

    class SCDensity : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCDensity& sceneContext;
            DensityContainer* densityContainer;
            csl::fnd::IAllocator* allocator;

        public:
            Impl(SCDensity& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCDensity);

        virtual void Initialize(const InitializeInfo& initializeInfo) override;
        virtual void UnkFunc1() override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual void UnkFunc7();
    };
}
