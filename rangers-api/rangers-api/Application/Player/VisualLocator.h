#pragma once

namespace app::player {
    class VisualLocator : public hh::fnd::ReferencedObject {
    public:
        hh::game::GameObject* gameObject;
        csl::math::Transform transform;

        DEFAULT_CREATE_FUNC(VisualLocator);

        virtual unsigned int GetNameHash() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual void AddCallback(GOCPlayerVisual* gocPlayerVisual) {}
        virtual void RemoveCallback(GOCPlayerVisual* gocPlayerVisual) {}
        virtual void UnkFunc5(GOCPlayerVisual* gocPlayerVisual, float a3) {}

        void SetTransform(const csl::math::Transform& transform);
        csl::math::Transform& GetTransform() const;
        void SetOwnerObject(hh::game::GameObject* gameObject);
    };
}
