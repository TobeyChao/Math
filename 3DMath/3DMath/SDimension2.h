#pragma once
namespace Soul
{
	namespace Core
	{
		class SDimension2
		{
		public:
			unsigned int width;
			unsigned int height;

			SDimension2() = default;
			SDimension2(unsigned int x_in, unsigned int y_in);
			SDimension2(const SDimension2& src);

			SDimension2& operator=(const SDimension2& M);

			SDimension2& operator+= (const SDimension2& V2);

			SDimension2& operator-= (const SDimension2& V2);

			SDimension2& operator*= (const unsigned int S);

			SDimension2& operator/= (const unsigned int S);

			SDimension2  operator+ (const SDimension2& V) const;

			SDimension2  operator- (const SDimension2& V) const;

			SDimension2  operator* (const unsigned int S);

			SDimension2  operator/ (const unsigned int S);
		};
	}
}