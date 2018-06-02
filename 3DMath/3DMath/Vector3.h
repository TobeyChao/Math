#pragma once
#include <iostream>
namespace Soul
{
	namespace Core
	{
		class Vector3
		{
		public:
			Vector3();
			Vector3(float in_x, float in_y, float in_z);
			Vector3(const Vector3& vec3);

			float Magnitude() const;
			void Normalize();
			float Dot(const Vector3 &vec3);
			Vector3 Cross(const Vector3 &vec3);

			//Operators
			friend std::ostream &operator<<(std::ostream &output, const Vector3 &vec3);
			Vector3& operator=(const Vector3& vec3);
			Vector3 operator+(const Vector3 &v) const;
			Vector3 operator-();
			Vector3 operator-(const Vector3 &v) const;
			Vector3 operator*(float num) const;
			Vector3 operator/(float num) const;
			Vector3 &operator+=(const Vector3 &v);
			Vector3 &operator-=(const Vector3 &v);
			Vector3 &operator*=(float num);
			Vector3 &operator/=(float num);
			//Returns true if vectors different.
			bool operator!=(Vector3 &v) const;
		protected:

		public:
			float x;
			float y;
			float z;
		};
		float Dot(const Vector3 &vec3L, const Vector3 &vec3R);
		Vector3 Cross(const Vector3 &vec3L, const Vector3 &vec3R);
		float Magnitude(Vector3& vec3);
		void Normalize(Vector3& vec3);
	}
}