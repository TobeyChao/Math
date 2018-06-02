#pragma once
#include <iostream>

namespace Soul
{
	namespace Core
	{
		class Vector4
		{
		public:
			Vector4();
			Vector4(float in_x, float in_y, float in_z, float in_w);
			Vector4(const Vector4& vec4);

			//Operators
			friend std::ostream &operator<<(std::ostream &output, const Vector4 &vec4);
			Vector4& operator=(const Vector4& vec4);
			Vector4 operator+(const Vector4 &v) const;
			Vector4 operator-();
			Vector4 operator-(const Vector4 &v) const;
			Vector4 operator*(float num) const;
			Vector4 operator/(float num) const;
			Vector4 &operator+=(const Vector4 &v);
			Vector4 &operator-=(const Vector4 &v);
			Vector4 &operator*=(float num);
			Vector4 &operator/=(float num);
			//Returns true if vectors different.
			bool operator!=(Vector4 &v) const;

		public:
			float x;
			float y;
			float z;
			float w;
		};
	}
}
