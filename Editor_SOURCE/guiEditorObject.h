#pragma once
#include "..\\Engine_SOURCE\\niGameObject.h"

namespace gui
{
	class EditorObject : public ni::GameObject
	{
	public:
		EditorObject();
		virtual ~EditorObject();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	};
}
