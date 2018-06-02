#include "Vector2.h"

using namespace Soul;
using namespace Core;

namespace Soul
{
	namespace Core
	{
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

		SVector2& SVector2::operator=(const SVector2& M)
		{
			x = M.x;
			y = M.y;
			return *this;
		}
		SVector2 SVector2::operator-()
		{
			return SVector2(-x, -y);
		}
		SVector2& SVector2::operator-= (SVector2 V2)
		{
			x -= V2.x;
			y -= V2.y;
			return *this;
		}
		SVector2& SVector2::operator+= (SVector2 V2)
		{
			x += V2.x;
			y += V2.y;
			return *this;
		}
		SVector2 & SVector2::operator*=(float S)
		{
			x *= S;
			y *= S;
			return *this;
		}
		SVector2 & SVector2::operator/=(float S)
		{
			x /= S;
			y /= S;
			return *this;
		}
		SVector2 SVector2::operator+(SVector2 V)
		{
			return SVector2(*this) += V;
		}
		SVector2 SVector2::operator-(SVector2 V)
		{
			return SVector2(*this) -= V;
		}
		SVector2 SVector2::operator*(float S)
		{
			return SVector2(*this) *= S;
		}

		SVector2 SVector2::operator/(float S)
		{
			return SVector2(*this) /= S;
		}
	}
}