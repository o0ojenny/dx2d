#include "niEntity.h"


namespace ni
{
	Entity::Entity()
		: mName(L"")
		, mColliderID((UINT64)this)
	{

	}

	Entity::~Entity()
	{
	}

}
