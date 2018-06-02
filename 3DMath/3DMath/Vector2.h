#pragma once

namespace Soul
{
	namespace Core
	{
		class SVector2
		{
		public:
			SVector2(float x_in, float y_in);
			SVector2(const SVector2& src);

			SVector2& operator=(const SVector2& M);

			SVector2 operator-();

			SVector2& operator+= (SVector2 V2);

			SVector2& operator-= (SVector2 V2);

			SVector2& operator*= (float S);

			SVector2& operator/= (float S);

			SVector2  operator+ (SVector2 V);

			SVector2  operator- (SVector2 V);

			SVector2  operator* (float S);

			SVector2  operator/ (float S);

		private:
			float x;
			float y;
		};
	}
}