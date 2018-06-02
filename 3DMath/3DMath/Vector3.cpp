#include "Vector3.h"
#include <math.h>

namespace Soul
{
	namespace Core
	{
		Vector3::Vector3()
		{
			x = 0;
			y = 0;
			z = 0;
		}
		Vector3::Vector3(float in_x, float in_y, float in_z)
			:
			x(in_x),
			y(in_y),
			z(in_z)
		{}
		Vector3::Vector3(const Vector3& vec3)
		{
			x = vec3.x;
			y = vec3.y;
			z = vec3.z;
		}
		float Vector3::Magnitude() const
		{
			return sqrt(x * x + y * y + z * z);
		}
		void Vector3::Normalize()
		{
			float length = Magnitude();
			(*this) /= length;
		}
		float Vector3::Dot(const Vector3 &vec3)
		{
			return x * vec3.x + y * vec3.y + z * vec3.z;
		}
		Vector3 Vector3::Cross(const Vector3 &vec3)
		{
			return Vector3((y * vec3.z) - (z * vec3.y),
				(z * vec3.x) - (x * vec3.z),
				(x * vec3.y) - (y * vec3.x));
		}
		Vector3 & Vector3::operator=(const Vector3 & vec3)
		{
			x = vec3.x;
			y = vec3.y;
			z = vec3.z;
			std::cout << this << " " << &vec3;
			return *this;
		}
		Vector3 Vector3::operator+(const Vector3 &vec3) const
		{
			return Vector3(x + vec3.x, y + vec3.y, z + vec3.z);
		}
		Vector3 Vector3::operator-()
		{
			return Vector3(-x, -y, -z);
		}
		Vector3 Vector3::operator-(const Vector3 &vec3) const
		{
			return Vector3(x - vec3.x, y - vec3.y, z - vec3.z);
		}
		Vector3 Vector3::operator*(float num) const
		{
			return Vector3(x * num, y * num, z * num);
		}
		Vector3 Vector3::operator/(float num) const
		{
			return Vector3(x / num, y / num, z / num);
		}
		Vector3 &Vector3::operator+=(const Vector3 &vec3)
		{
			x += vec3.x;
			y += vec3.y;
			z += vec3.z;
			return *this;
		}
		Vector3 &Vector3::operator-=(const Vector3 &vec3)
		{
			x -= vec3.x;
			y -= vec3.y;
			z -= vec3.z;
			return *this;
		}
		Vector3 &Vector3::operator*=(float num)
		{
			x *= num;
			y *= num;
			z *= num;
			return *this;
		}
		Vector3 &Vector3::operator/=(float num)
		{
			x /= num;
			y /= num;
			z /= num;
			return *this;
		}
		bool Vector3::operator!=(Vector3 &vec3) const
		{
			return x != vec3.x || y != vec3.y || z != vec3.z;
		}
		std::ostream &operator<<(std::ostream &output, const Vector3 &vec3)
		{
			output << "X: " << vec3.x << " Y: " << vec3.y << " Z: " << vec3.z;
			return output;
		}
		float Dot(const Vector3 & vec3L, const Vector3 & vec3R)
		{
			return vec3L.x * vec3R.x + vec3L.y * vec3R.y + vec3L.z * vec3R.z; return 0.0f;
		}
		Vector3 Cross(const Vector3 & vec3L, const Vector3 & vec3R)
		{
			return Vector3((vec3L.y * vec3R.z) - (vec3L.z * vec3R.y),
				(vec3L.z * vec3R.x) - (vec3L.x * vec3R.z),
				(vec3L.x * vec3R.y) - (vec3L.y * vec3R.x));
		}
		float Magnitude(Vector3 & vec3)
		{
			return sqrt(vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z);
		}
		void Normalize(Vector3 & vec3)
		{
			float length = Magnitude(vec3);
			if (length != 0.0f)
			{
				vec3 /= length;
			}
		}
	}
}