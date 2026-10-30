#pragma once

namespace app {
    class ObjCamera : public hh::game::GameObject {
    public:
        app_cmn::camera::GOCCamera* gocCamera;
        csl::ut::MoveArray<void*> unk205[1];
        uint32_t unk206;
        csl::fnd::Mutex mutex;

		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
        virtual app_cmn::camera::CameraController* CreateCamera(unsigned int id) = 0;
        virtual void OC_UnkFunc0() {} // Related to Level Editor?
        virtual void SetCamera() = 0;

        GAMEOBJECT_CLASS_DECLARATION(ObjCamera)
    };

    template<typename Camera, typename CameraSpawner>
    class TObjCamera : public ObjCamera {
    public:
        virtual app_cmn::camera::CameraController* CreateCamera(unsigned int id) override {
            auto* allocator = gocCamera->GetAllocator();
            auto* camera = new (allocator) Camera{ allocator };
            gocCamera->AddController(camera, id);
            camera->name = name;
            SetupCamera(GetWorldDataByClass<CameraSpawner>(), id);
            return camera;
        }
        virtual void SetCamera() override {
            if (auto* controller = gocCamera->GetControllerByID(0)) {
                SetupCamera(GetWorldDataByClass<CameraSpawner>(), 0);
                controller->UnkFunc5();
            }
        }
        virtual void SetupCamera(const CameraSpawner* spawnerData, unsigned int id) = 0;
    };
}
