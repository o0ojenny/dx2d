#pragma once
#include "niGameObject.h"
#include "niRenderer.h"

namespace ni
{
    using namespace renderer;
    class Feed : public GameObject
    {
    public:
        Feed();
        ~Feed();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render() override;

       ObjectInfo GetFeedInfo() { return mFeedInfo; }
       void SetFeedInfo(ObjectInfo info) { mFeedInfo = info; }

    private:
        ObjectInfo mFeedInfo;
    };
}
