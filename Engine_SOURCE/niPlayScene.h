#pragma once
//#include "niScene.h"
#include "..\Engine_SOURCE\niScene.h"

namespace ni
{
    class PlayScene : public Scene
    {
    public:
        PlayScene();
        virtual ~PlayScene();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render() override;
    };
}
