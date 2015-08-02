#pragma once

namespace MagicGear
{
	class Ray
	{
	public:
		Vector3 dir;
		Vector3 origin;

	public:
		Ray(void):dir(1,0,0),origin(0,0,0)
		{}
		~Ray(void){}
	};
}//namespace MagicGear