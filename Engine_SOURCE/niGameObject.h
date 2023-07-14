#pragma once
#include "niEntity.h"
#include "niComponent.h"
#include "niRenderer.h"
#include "niScript.h"

namespace ni
{
	class GameObject : public Entity
	{
	public:
		enum class eState
		{
			Active,
			Paused,
			Dead
		};

		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		eState GetState() { return mState; }
		void SetState(eState state) { mState = state; }

		renderer::ObjectInfo GetObjectInfo() { return mObjectInfo; }
		void SetObjectInfo(renderer::ObjectInfo objectinfo) { mObjectInfo = objectinfo; }

		template <typename T>
		T* GetComponent()
		{
			T* component;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component != nullptr)
					return component;
			}
			return nullptr;
		}

		template<typename T>
		T* AddComponent()
		{
			T* comp = new T();
			
			Component* buff = dynamic_cast<Component*>(comp);

			if (buff == nullptr)
				return nullptr;
			
			mComponents.push_back(buff);
			comp->SetOwner(this);

			return comp;
		}

		void SetState(eState state) { mState = state; }
		eState GetState() { return mState; }


	private:
		eState mState;
		renderer::ObjectInfo mObjectInfo;

		std::vector<Component*> mComponents;
		std::vector<Script*> mScripts;
	};
}
