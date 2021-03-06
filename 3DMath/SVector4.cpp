#include "SVector4.h"

namespace Soul
{
	namespace Core
	{
		SVector4::SVector4()
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}
		SVector4::SVector4(float in_x, float in_y, float in_z, float in_w)
			:
			x(in_x),
			y(in_y),
			z(in_z),
			w(in_w)
		{}
		SVector4::SVector4(const SVector4 &vec4)
		{
			x = vec4.x;
			y = vec4.y;
			z = vec4.z;
			w = vec4.w;
		}

		SVector4 &SVector4::operator=(const SVector4 &vec4)
		{
			x = vec4.x;
			y = vec4.y;
			z = vec4.z;
			w = vec4.w;
			return *this;
		}
		SVector4 SVector4::operator+(const SVector4 &v) const
		{
			return SVector4(x + v.x, y + v.y, z + v.z, w + v.w);
		}
		SVector4 SVector4::operator-() const
		{
			return SVector4(-x, -y, -z, -w);
		}
		SVector4 SVector4::operator-(const SVector4 &v) const
		{
			return SVector4(x - v.x, y - v.y, z - v.z, w - v.w);
		}
		SVector4 SVector4::operator*(float num) const
		{
			return SVector4(x * num, y * num, z * num, w * num);
		}
		SVector4 SVector4::operator/(float num) const
		{
			return SVector4(x / num, y / num, z / num, w / num);
		}
		SVector4 &SVector4::operator+=(const SVector4 &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;
			return *this;
		}
		SVector4 &SVector4::operator-=(const SVector4 &v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;
			return *this;
		}
		SVector4 &SVector4::operator*=(float num)
		{
			x *= num;
			y *= num;
			z *= num;
			w *= num;
			return *this;
		}
		SVector4 &SVector4::operator/=(float num)
		{
			x /= num;
			y /= num;
			z /= num;
			w /= num;
			return *this;
		}
		bool SVector4::operator!=(const SVector4 &v) const
		{
			return x != v.x || y != v.y || z != v.z || w != v.w;
		}
		std::ostream & operator<<(std::ostream &output, const SVector4 &vec4)
		{
			output << "X: " << vec4.x << " Y: " << vec4.y << " Z: " << vec4.z << " W: " << vec4.w;
			return output;
		}
	}
}