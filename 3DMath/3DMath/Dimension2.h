#pragma once
#include <Windows.h>
namespace Soul
{
	namespace Core
	{
		class Dimension2
		{
		public:
			UINT32 width;
			UINT32 height;

			Dimension2() = default;
			Dimension2(UINT32 x_in, UINT32 y_in);
			Dimension2(const Dimension2& src);

			Dimension2& operator=(const Dimension2& M);

			Dimension2& operator+= (Dimension2 V2);

			Dimension2& operator-= (Dimension2 V2);

			Dimension2& operator*= (UINT32 S);

			Dimension2& operator/= (UINT32 S);

			Dimension2  operator+ (Dimension2 V);

			Dimension2  operator- (Dimension2 V);

			Dimension2  operator* (UINT32 S);

			Dimension2  operator/ (UINT32 S);

		};
	}
}