#pragma once

namespace ni::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Particle,
		MeshRenderer,
		Script,
		Camera,
		End,
	};

	enum class eLayerType
	{
		Background,
		Player, 
		Monster,
		UI,
		End,
	};

	enum class eResourceType
	{
		Texture,
		Shader,
		Material,
		Mesh,
		End,
	};

	enum class eColliderType
	{
		Rect,
		Circle,
		Sphere,
		Cube,
		End,
	};
}