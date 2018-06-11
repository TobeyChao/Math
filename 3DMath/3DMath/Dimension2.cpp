#include "Dimension2.h"

namespace Soul
{
	namespace Core
	{
		Dimension2::Dimension2(UINT32 x_in, UINT32 y_in)
			:
			width(x_in),
			height(y_in)
		{}

		Dimension2::Dimension2(const Dimension2& src)
			:
			width(src.width),
			height(src.height)
		{}

		Dimension2& Dimension2::operator=(const Dimension2& M)
		{
			width = M.width;
			height = M.height;
			return *this;
		}
		Dimension2& Dimension2::operator-= (Dimension2 V2)
		{
			width -= V2.width;
			height -= V2.height;
			return *this;
		}
		Dimension2& Dimension2::operator+= (Dimension2 V2)
		{
			width += V2.width;
			height += V2.height;
			return *this;
		}
		Dimension2 & Dimension2::operator*=(UINT32 S)
		{
			width *= S;
			height *= S;
			return *this;
		}
		Dimension2 & Dimension2::operator/=(UINT32 S)
		{
			width /= S;
			height /= S;
			return *this;
		}
		Dimension2 Dimension2::operator+(Dimension2 V)
		{
			return Dimension2(*this) += V;
		}
		Dimension2 Dimension2::operator-(Dimension2 V)
		{
			return Dimension2(*this) -= V;
		}
		Dimension2 Dimension2::operator*(UINT32 S)
		{
			return Dimension2(*this) *= S;
		}

		Dimension2 Dimension2::operator/(UINT32 S)
		{
			return Dimension2(*this) /= S;
		}
	}
}