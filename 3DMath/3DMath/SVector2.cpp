#include "SVector2.h"
#include <cmath>

using namespace Soul;
using namespace Core;

namespace Soul
{
	namespace Core
	{
		SVector2::SVector2()
			:
			x(0.0f),
			y(0.0f)
		{}
		SVector2::SVector2(float x_in, float y_in)
			:
			x(x_in),
			y(y_in)
		{}
		SVector2::SVector2(const SVector2& src)
			:
			x((float)src.x),
			y((float)src.y)
		{}
		float SVector2::Magnitude() const
		{
			return (float)sqrt(x * x + y * y);
		}
		void SVector2::Normalize()
		{
			float length = Magnitude();
			if (length != 0.0f)
			{
				(*this) /= length;
			}
		}
		SVector2 SVector2::MidPoint(const SVector2 & V2) const
		{
			return SVector2((x + V2.x) * 0.5f, (y + V2.y) * 0.5f);
		}
		SVector2& SVector2::operator=(const SVector2& M)
		{
			x = M.x;
			y = M.y;
			return *this;
		}
		SVector2 SVector2::operator-() const
		{
			return SVector2(-x, -y);
		}
		SVector2& SVector2::operator-= (const SVector2& V2)
		{
			x -= V2.x;
			y -= V2.y;
			return *this;
		}
		SVector2& SVector2::operator+= (const SVector2& V2)
		{
			x += V2.x;
			y += V2.y;
			return *this;
		}
		SVector2 & SVector2::operator*=(const float S)
		{
			x *= S;
			y *= S;
			return *this;
		}
		SVector2 & SVector2::operator/=(const float S)
		{
			x /= S;
			y /= S;
			return *this;
		}
		SVector2 SVector2::operator+(const SVector2& V) const
		{
			return SVector2(*this) += V;
		}
		SVector2 SVector2::operator-(const SVector2& V) const
		{
			return SVector2(*this) -= V;
		}
		SVector2 SVector2::operator*(const float S)
		{
			return SVector2(*this) *= S;
		}
		SVector2 SVector2::operator/(const float S)
		{
			return SVector2(*this) /= S;
		}
		bool SVector2::operator!=(const SVector2 & v) const
		{
			return x != v.x || y != v.y;
		}
		/*************non-member-function*************/
		float Cross(const SVector2& vec2L, const SVector2& vec2R)
		{
			return vec2L.x * vec2R.y - vec2L.y * vec2R.x;
		}
		float Dot(const SVector2& vec2L, const SVector2& vec2R)
		{
			return vec2L.x * vec2R.x + vec2L.y * vec2R.y;
		}
	}
}