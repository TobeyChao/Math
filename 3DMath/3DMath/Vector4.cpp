#include "Vector4.h"

namespace Soul
{
	namespace Core
	{
		Vector4::Vector4()
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

		Vector4::Vector4(float in_x, float in_y, float in_z, float in_w)
			:
			x(in_x),
			y(in_y),
			z(in_z),
			w(in_w)
		{}

		Vector4::Vector4(const Vector4 & vec4)
		{
			x = vec4.x;
			y = vec4.y;
			z = vec4.z;
			w = vec4.w;
		}

		Vector4 & Vector4::operator=(const Vector4 & vec4)
		{
			x = vec4.x;
			y = vec4.y;
			z = vec4.z;
			w = vec4.w;
			return *this;
		}
		Vector4 Vector4::operator+(const Vector4 & v) const
		{
			return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
		}
		Vector4 Vector4::operator-()
		{
			return Vector4(-x, -y, -z, -w);
		}
		Vector4 Vector4::operator-(const Vector4 & v) const
		{
			return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
		}
		Vector4 Vector4::operator*(float num) const
		{
			return Vector4(x * num, y * num, z * num, w * num);
		}
		Vector4 Vector4::operator/(float num) const
		{
			return Vector4(x / num, y / num, z / num, w / num);
		}
		Vector4 & Vector4::operator+=(const Vector4 & v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;
			return *this;
		}
		Vector4 & Vector4::operator-=(const Vector4 & v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;
			return *this;
		}
		Vector4 & Vector4::operator*=(float num)
		{
			x *= num;
			y *= num;
			z *= num;
			w *= num;
			return *this;
		}
		Vector4 & Vector4::operator/=(float num)
		{
			x /= num;
			y /= num;
			z /= num;
			w /= num;
			return *this;
		}
		bool Vector4::operator!=(Vector4 & v) const
		{
			return x != v.x || y != v.y || z != v.z || w != v.w;
		}
		std::ostream & operator<<(std::ostream & output, const Vector4 & vec4)
		{
			output << "X: " << vec4.x << " Y: " << vec4.y << " Z: " << vec4.z << " W: " << vec4.w;
			return output;
		}
	}
}