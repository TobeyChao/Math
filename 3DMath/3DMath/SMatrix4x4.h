#pragma once
#include "SVector3.h"

namespace Soul
{
	namespace Core
	{
		constexpr int matrixRow = 4;
		constexpr int matrixColumn = 4;

		class SMatrix4x4
		{
		public:
			SMatrix4x4();
			friend std::ostream &operator<<(std::ostream &output, const SMatrix4x4 &mat4x4);
			SMatrix4x4& operator=(const SMatrix4x4& Float4);
			SMatrix4x4 operator+(SMatrix4x4& mat4x4);
			SMatrix4x4& operator+=(SMatrix4x4& mat4x4);
			SMatrix4x4 operator-(SMatrix4x4& mat4x4);
			SMatrix4x4& operator-=(SMatrix4x4& mat4x4);
			SMatrix4x4 operator*(SMatrix4x4& mat4x4) const;
			bool operator==(const SMatrix4x4 & mat4x4) const;
			bool operator!=(const SMatrix4x4 & mat4x4) const;
		public:
			
			float mat[matrixRow][matrixColumn];
		};
		/*************non-member-function*************/
		void VectorSinCos(SVector3* pSin, SVector3* pCos, const SVector3 angle);
		void ScalarSinCos(float* pSin, float* pCos, const float angle);
		SMatrix4x4 Matrix4x4Identity();
		SMatrix4x4 MatrixRotationRollPitchYaw(float pitch, float yaw, float roll);
		SMatrix4x4 MatrixPerspectiveFovLH(float fovy, float aspect, float nearZ, float farZ);
		SMatrix4x4 MatrixOrthographicLH(float width, float height, float nearZ, float farZ);
		SMatrix4x4 MatrixLookAtLH(SVector3 eye, SVector3 at, SVector3 up);
		void MatrixTranspose(SMatrix4x4 & mat4x4);
		SMatrix4x4 MatrixTranslation(SVector3 pos);
		SMatrix4x4 MatrixTranslation(float offset_x, float offset_y, float offset_z);
		SMatrix4x4 MatrixRotationX(float angle);
		SMatrix4x4 MatrixRotationY(float angle);
		SMatrix4x4 MatrixRotationZ(float angle);
		SMatrix4x4 MatrixRotationAboutAxis(const SVector3& axis, float angle);
		SMatrix4x4 MatrixScaling(float scale_x, float scale_y, float scale_z);
	}
}