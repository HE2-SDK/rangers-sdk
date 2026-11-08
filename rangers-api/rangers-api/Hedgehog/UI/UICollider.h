#pragma once

namespace hh::ui {
    class UICollider : public fnd::ReferencedObject {
    public:
        char byte18;
        bool enabled;
        int priority;
        int64_t qword20;
        UICollider* qword28;
        csl::ut::VariableString name;

        UICollider(csl::fnd::IAllocator* allocator, int priority);

        virtual void* GetRuntimeTypeInfo() const;
        virtual void UpdateRect() {}
        virtual void UnkFunc1() {}
        virtual bool Update(fnd::SUpdateInfo& updateInfo) = 0;
        virtual bool UnkFunc3(csl::math::Vector4& retValue) = 0;
    };

    class UIColliderPane : public UICollider {
    public:
        fnd::Handle<SurfRideCastHandle> paneCast;
        float oword44[4];
        int dword54;
        int dword58;
        int dword5C;
        int dword60;
        int dword64;
        int dword68;
        int dword6C;
        int dword70;

        UIColliderPane(csl::fnd::IAllocator* allocator, int priority, fnd::Handle<SurfRideCastHandle>& cast);
        
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void UpdateRect() override;
        virtual bool Update(fnd::SUpdateInfo& updateInfo) override;
        virtual bool UnkFunc3(csl::math::Vector4& retValue) override;
    };
}
