#pragma once
#include "SVector3.h"
namespace Soul
{
	namespace Core
	{
		class SQuaternion
		{
		public:
			float w;
			float x;
			float y;
			float z;
		public:
			SQuaternion();
			SQuaternion(float _w, float _x, float _y, float _z);
			SQuaternion(const SQuaternion &quaternion);
		};
		SQuaternion QuaternionIdentity();
		SQuaternion QuaternionRotationX(const float angle);
		SQuaternion QuaternionRotationY(const float angle);
		SQuaternion QuaternionRotationZ(const float angle);
		SQuaternion QuaternionRotationAboutAxis(const SVector3 &axis, float angle);
		SQuaternion QuaternionRotationObjectToInertial(float pitch, float yaw, float roll);
	}
}