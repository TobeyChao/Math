#pragma once

namespace Soul
{
	namespace Core
	{
		class SVector2
		{
		public:
			SVector2();
			SVector2(float x_in, float y_in);
			SVector2(const SVector2& src);

			float Magnitude() const;

			void Normalize();

			SVector2 MidPoint(const SVector2& V2) const;

			SVector2& operator=(const SVector2& M);

			SVector2 operator-() const;

			SVector2& operator+= (const SVector2& V2);

			SVector2& operator-= (const SVector2& V2);

			SVector2& operator*= (const float S);

			SVector2& operator/= (const float S);

			SVector2  operator+ (const SVector2& V) const;

			SVector2  operator- (const SVector2& V) const;

			SVector2  operator* (const float S);

			SVector2  operator/ (const float S);

			bool operator!=(const SVector2 &v) const;
		public:
			float x;
			float y;
		};
		/*************non-member-function*************/
		float Cross(const SVector2&vec2L, const SVector2& vec2R);
		float Dot(const SVector2& vec2L, const SVector2& vec2R);
	}
}