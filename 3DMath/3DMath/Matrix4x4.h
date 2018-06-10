#pragma once
#include "Vector3.h"
#include "Vector4.h"

namespace Soul
{
	namespace Core
	{
		#define Column 4
		#define Row 4

		class Matrix4x4
		{
		public:
			Matrix4x4();
			virtual ~Matrix4x4();
			friend std::ostream &operator<<(std::ostream &output, const Matrix4x4 &mat4x4);
			Matrix4x4& operator=(const Matrix4x4& Float4);
			Matrix4x4 operator+(Matrix4x4& mat4x4);
			Matrix4x4& operator+=(Matrix4x4& mat4x4);
			Matrix4x4 operator-(Matrix4x4& mat4x4);
			Matrix4x4& operator-=(Matrix4x4& mat4x4);
			Matrix4x4 operator*(Matrix4x4& mat4x4);
			bool operator==(const Matrix4x4 & mat4x4) const;
			bool operator!=(const Matrix4x4 & mat4x4) const;
		protected:

		public:
			float mat[Row][Column];
		};

		void ScalarSinCos(float* pSin, float* pCos, float angle);
		Matrix4x4 Matrix4x4Identity();
		Matrix4x4 MatrixPerspectiveFovLH(float fovy, float aspect, float near, float far);
		Matrix4x4 MatrixLookAtLH(Vector3 eye, Vector3 at, Vector3 up);
		void MatrixTranspose(Matrix4x4 & mat4x4);
		Matrix4x4 MatrixTranslation(float offset_x, float offset_y, float offset_z);
		Matrix4x4 MatrixRotationX(float angle);
		Matrix4x4 MatrixRotationY(float angle);
		Matrix4x4 MatrixRotationZ(float angle);
		Matrix4x4 MatrixScaling(float scale_x, float scale_y, float scale_z);
	}
}