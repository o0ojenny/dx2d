#pragma once
#include "JEngine.h"

namespace ni
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }
		void SetColliderID(UINT64 id) { mColliderID = id; }
		UINT64 GetColliderID() { return mColliderID; }

	private:
		std::wstring mName;
		UINT64 mColliderID;
	};
}
