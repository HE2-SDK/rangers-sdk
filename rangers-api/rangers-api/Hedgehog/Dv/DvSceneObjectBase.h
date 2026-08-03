#pragma once

namespace hh::dv {
    class DvSceneObjectBase : public fnd::ReferencedObject {
    public:
        fnd::Handle<DvStandardCharacter> dvStandardChar;
        void* pose;
        unsigned int visualModelNameHash;
        int unk2;

        virtual void* ReturnA2(void* a2);
        virtual void SetModelResource(hh::gfx::ResModel* resource) {};
        virtual void* VisualModelRelated0(gfx::ResVertexAnimationTexture* resVAT, void* a3, bool a4);
        virtual void SetMatAnimTime(gfx::ResAnimMaterial* matAnim, float time, bool loop);
        virtual void SetVisAnimTime(gfx::ResAnimVis* visAnim, float time, bool loop);
        virtual void SetTexSrtTime(gfx::ResAnimTexSrt* uvAnim, float time, bool loop);
        virtual void* VisualModelRelated4(void* a2);
        virtual void* VisualModelRelated5(void* a2);
        virtual void* VisualModelRelated6(void* a2);
        virtual void* VisualModelRelated7(void* a2);
        virtual void SetTransform(const csl::math::Transform transform);
        virtual void SetVisibility0(bool visible, bool unk);
        virtual void SetVisibility1(bool visible);
        virtual void SetVisualModelUnk0(double unk);
        virtual anim::GOCAnimator* GetGOCAnimator();
        virtual bool UnkTransform(void* a2, float a3, char a4, csl::math::Transform* transform);
        virtual void SetAnimatorState(const char* floatVarName, const char* stateName);
        virtual void* GetUnkGOCAnimator0(void* a2, void* a3, void* a4, int a5); // only a5 is used
        virtual bool SetAnimatorState(const char* stateName, int layer);
        virtual void* GetGOCAnimatorUnk0(void* a2);
        virtual bool VisualModelIsAcceptingMessages();
        virtual void ShowDebugDraw();
        virtual void HideDebugDraw();

        hh::dv::DvStandardCharacter* GetCharacterObject() const;
        void DeleteCharacterObject(bool killObject);
        void SetModelNameHash(unsigned int hash);
        void SetModelNameHash(const char* name);
        void InitializeObject(anim::ResAnimator* animator, anim::ResSkeleton* skl);
        void SetPose(anim::ResSkeleton* skl);

        DvSceneObjectBase(csl::fnd::IAllocator* allocator, hh::dv::DvStandardCharacter* character);
    };
}
