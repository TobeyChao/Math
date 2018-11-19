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
			SQuaternion(const SQuaternion& SQuaternion);


		};
		SQuaternion QuaternionIdentity();
		SQuaternion QuaternionRotationX(float angle);
		SQuaternion QuaternionRotationY(float angle);
		SQuaternion QuaternionRotationZ(float angle);
		SQuaternion QuaternionRotationAboutAxis(const SVector3& axis, float angle);
		SQuaternion QuaternionRotationInertialToObject(float pitch, float yaw, float roll);
		SQuaternion QuaternionRotationObjectToInertial(float pitch, float yaw, float roll);
	}
}