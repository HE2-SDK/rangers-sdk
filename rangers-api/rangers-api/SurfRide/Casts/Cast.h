#pragma once

namespace SurfRide {
    class Cast;
    class DrawInterface;
    class CastExtension;

    class CastListener {
    public:
        virtual ~CastListener();
        virtual void BeginRenderCastEx(Cast* cast, DrawInterface* drawInterface, void* uiRenderInfo);
        virtual int64_t Unk1();
        virtual void EndRenderCastEx(Cast* cast, DrawInterface* drawInterface, void* uiRenderInfo);
        virtual int64_t Unk3();
        virtual void BeginRenderCast(Cast* cast, DrawInterface* drawInterface, void* uiRenderInfo);
        virtual int64_t Unk5();
        virtual void EndRenderCast(Cast* cast, DrawInterface* drawInterface, void* uiRenderInfo);
        virtual int64_t Unk7();
        virtual int64_t Unk8();
    };

    class Scene;
    class Cast : public ReferencedObject {
    public:
		struct ExtensionCollection {
			csl::ut::MoveArray<CastExtension*> extensions;
			Cast* cast;

			ExtensionCollection(csl::fnd::IAllocator* allocator);
            void AddExtension(CastExtension* extension);
		};

        enum class Flag {
            ENABLE_CROP_INDEX_0 = 14,
            ENABLE_CROP_INDEX_1 = 15,
        };

        Transform* transform;
        RefPtr<Blur> blurEffect;
        RefPtr<Reflect> reflectEffect;
        uint32_t unk4;
        CastListener* listener;
        SRS_CASTNODE* castData;
        Layer* layer;
        Cast* parentCast;
        csl::ut::MoveArray<SurfRide::Cast*> children;
        SRS_MOTION* motion;
        uint32_t flags;
        bool unk8;
        bool is3D;
        uint16_t unk9;
        uint16_t unk9a;
        uint64_t unk10;
        Vector3 position;
        ExtensionCollection extensionCollection;
        bool unk14;

        Cast(SRS_CASTNODE* castData, Cast* parentCast, Layer* layer);
        UserData GetUserData();
        void SetHideFlag(bool enabled);
        void InitializeTransform2D(Transform* transform, SRS_TRS2D* cell);
        void InitializeTransform3D(Transform* transform, SRS_TRS3D* cell);
        Scene* GetScene();
        void CreateEffectCast(void* effectData);
        SRS_TEXTURELIST* GetTextureListData(int index) const;
        TextureList** GetTextureLists() const;

        static Vector2 CalcPivot(float width, float height, EPivotType pivotType, const Vector2& customPivot);

        virtual void* GetRuntimeTypeInfo() const;
        virtual bool UnkFunc2();
        virtual void Render(DrawInterface* drawInterface, void* uiRenderInfo) {}
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) {}
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) {}
        virtual void CalcTrackTypeCropIndex0(float time, const SRS_TRACK* track) {}
        virtual void CalcTrackTypeCropIndex1(float time, const SRS_TRACK* track) {}
        virtual void* GetCellProbably() const;
        virtual void SetCellProbably(void* cell) {}
        virtual unsigned int GetCellCount() const;
        virtual void UpdateThis(float time, const Cast* parentCast);
        virtual uint64_t UnkFunc12();

        inline void SetPosition(const Vector3& pos) {
			transform->position = pos;
			transform->dirtyFlag.flags.bits |= transform->dirtyFlag.transformAny.bits;
        }

        inline csl::ut::MoveArray<SurfRide::Cast*> GetChildren() const {
            return children;
        }
    };

	struct CastCollection {
		SRS_LAYER* layer;
		SRS_CASTNODE* current;
		SRS_CASTNODE* end;
	};

	struct CastIterator {
		SRS_LAYER* layer;
		SRS_CASTNODE* cast;

		void Next();
		SRS_CASTNODE::Type GetType() const;
		const char* GetName() const;
		bool IsSysfCast() const;
        UserData GetUserData() const;
	};
}
