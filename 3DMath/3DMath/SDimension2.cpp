#include "SDimension2.h"

namespace Soul
{
	namespace Core
	{
		SDimension2::SDimension2(unsigned int x_in, unsigned int y_in)
			:
			width(x_in),
			height(y_in)
		{}

		SDimension2::SDimension2(const SDimension2& src)
			:
			width(src.width),
			height(src.height)
		{}

		SDimension2& SDimension2::operator=(const SDimension2& M)
		{
			width = M.width;
			height = M.height;
			return *this;
		}
		SDimension2 & SDimension2::operator+=(const SDimension2 & V2)
		{
			width += V2.width;
			height += V2.height;
			return *this;
		}
		SDimension2 & SDimension2::operator-=(const SDimension2 & V2)
		{
			width -= V2.width;
			height -= V2.height;
			return *this;
		}
		SDimension2 & SDimension2::operator*=(unsigned int S)
		{
			width *= S;
			height *= S;
			return *this;
		}
		SDimension2 & SDimension2::operator/=(unsigned int S)
		{
			width /= S;
			height /= S;
			return *this;
		}
		SDimension2 SDimension2::operator+(const SDimension2 & V) const
		{
			return SDimension2(*this) += V;
		}
		SDimension2 SDimension2::operator-(const SDimension2 & V) const
		{
			return SDimension2(*this) -= V;
		}
		SDimension2 SDimension2::operator*(unsigned int S)
		{
			return SDimension2(*this) *= S;
		}

		SDimension2 SDimension2::operator/(unsigned int S)
		{
			return SDimension2(*this) /= S;
		}
	}
}