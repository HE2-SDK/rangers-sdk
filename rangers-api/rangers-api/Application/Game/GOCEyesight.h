#pragma once

namespace app::game {
    class GOCEyesight;

    class GOCEyesightListener {
    public:
        // Gets executed in GOCEyesight::Update..?
        virtual void OnEyesightUpdate(GOCEyesight* gocEyesight, const hh::fnd::SUpdateInfo& updateInfo) = 0;
    };

    class GOCEyesight : public hh::game::GOComponent, public hh::fnd::HFrameListener, public hh::physics::GOCColliderListener {
    public:
        class TargetInfo : public hh::fnd::ReferencedObject {
        public:
            int dword14;
            hh::fnd::Handle<hh::physics::GOCCollider> target;
            float targetSize;
            char byte24;

            bool IsTargetActive() const;
        };

        struct SearchInfo {
            int dword0;
            float searchAngle;
            float dword8;
            float searchDistance;

            void Setup(float searchAngle, float dword8, float searchDistance);
        };

        struct Description {
            hh::fnd::HFrame* frame;
            csl::math::Transform owordE0;
            SearchInfo searchInfo;
            int dword128;
            int colliderNameHash;
            bool unk0;
            int dword140;
            int collisionQueryNameHash;
            float dword194a198;
            bool unk1;
            int dword12C;
            int64_t qword130;
            int dword138;
            int dword13C;
            int dword1B0;
            bool unk2;
        };

        int colliderNameHash;
        int collisionQueryNameHash;
        hh::physics::GOCCollider* gocCollider;
        hh::physics::GOCCollisionQuery* gocCollisionQuery;
        csl::math::Transform owordC0;
        csl::math::Transform owordE0;
        hh::fnd::HFrame* frame;
        SearchInfo searchInfo;
        int dword128;
        int dword12C;
        int64_t qword130;
        int dword138;
        int dword13C;
        int dword140;
        csl::ut::MoveArray<hh::fnd::Reference<TargetInfo>> targetInfos;
        csl::ut::InplaceMoveArray<GOCEyesightListener*, 1> listeners;
        char byte190; // |= 0x10 has frame; |= 0x20 targetInfos updated?;
        float dword194;
        float dword198;
        hh::fnd::Handle<hh::game::GameObject> dword19C; // unsure about if it's GameObject
        csl::math::Vector4 oword1A0;
        int dword1B0;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        virtual void HFrameUpdatedCallback(const hh::fnd::HFrame* frame, bool unkParam) override;
        virtual void OnEnter(hh::physics::MsgTriggerEnter& msg) override;
        virtual void OnLeave(hh::physics::MsgTriggerLeave& msg) override;

        void SetFrame(hh::fnd::HFrame* hFrame);
        void SetCollider(hh::physics::GOCCollider* gocCollider);
        inline void SetCollisionQuery(hh::physics::GOCCollisionQuery* gocCollisionQuery) {
            this->gocCollisionQuery = gocCollisionQuery;
        }

        void Setup(const Description& desc);
        TargetInfo* GetReachableTarget() const; // pretty much guessed
        bool HasTarget() const;
        void AddListener(GOCEyesightListener* listener);

        GOCOMPONENT_CLASS_DECLARATION(GOCEyesight);
    };
}
