#pragma once
#include <iostream>
namespace Soul
{
	namespace Core
	{
		class SVector3
		{
		public:
			SVector3();
			SVector3(float in_x, float in_y, float in_z);
			SVector3(const SVector3& vec3);

			float Magnitude() const;
			void Normalize();
			float Dot(const SVector3 &vec3);
			SVector3 Cross(const SVector3 &vec3);

			//Operators
			friend std::ostream &operator<<(std::ostream &output, const SVector3 &vec3);
			SVector3& operator=(const SVector3& vec3);
			SVector3 operator+(const SVector3 &v) const;
			SVector3 operator-();
			SVector3 operator-(const SVector3 &v) const;
			SVector3 operator*(float num) const;
			SVector3 operator/(float num) const;
			SVector3 &operator+=(const SVector3 &v);
			SVector3 &operator-=(const SVector3 &v);
			SVector3 &operator*=(float num);
			SVector3 &operator/=(float num);
			//Returns true if vectors different.
			bool operator!=(SVector3 &v) const;
		protected:

		public:
			float x;
			float y;
			float z;
		};
		float Dot(const SVector3 &vec3L, const SVector3 &vec3R);
		SVector3 Cross(const SVector3 &vec3L, const SVector3 &vec3R);
		float Magnitude(SVector3& vec3);
		void Normalize(SVector3& vec3);
	}
}