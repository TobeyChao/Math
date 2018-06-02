#include "Matrix4x4.h"
#include <math.h>

namespace Soul
{
	namespace Core
	{
		Matrix4x4::Matrix4x4()
		{
			memset(mat, 0, sizeof(mat));
		}

		Matrix4x4::~Matrix4x4()
		{
		}
		std::ostream & operator<<(std::ostream & output, const Matrix4x4 & mat4x4)
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Column; j++)
				{
					output << mat4x4.mat[i][j] << " ";
				}
				std::cout << std::endl;
			}
			return output;
		}
		Matrix4x4 & Matrix4x4::operator=(const Matrix4x4 & mat4x4)
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Column; j++)
				{
					mat[i][j] = mat4x4.mat[i][j];
				}
			}
			return *this;
		}
		Matrix4x4 Matrix4x4::operator+(Matrix4x4 & mat4x4)
		{
			Matrix4x4 Mat4x4;
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Column; j++)
				{
					Mat4x4.mat[i][j] = mat[i][j] + mat4x4.mat[i][j];
				}
			}

			return Mat4x4;
		}
		Matrix4x4 & Matrix4x4::operator+=(Matrix4x4 & mat4x4)
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Column; j++)
				{
					this->mat[i][j] = mat[i][j] + mat4x4.mat[i][j];
				}
			}
			return *this;
		}
		Matrix4x4 Matrix4x4::operator-(Matrix4x4 & mat4x4)
		{

			Matrix4x4 Mat4x4;
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Column; j++)
				{
					Mat4x4.mat[i][j] = mat[i][j] - mat4x4.mat[i][j];
				}
			}
			return Mat4x4;
		}
		Matrix4x4 & Matrix4x4::operator-=(Matrix4x4 & mat4x4)
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Column; j++)
				{
					mat[i][j] = mat[i][j] - mat4x4.mat[i][j];
				}
			}
			return *this;
		}
		Matrix4x4 Matrix4x4::operator*(Matrix4x4 & mat4x4)
		{
			Matrix4x4 Mat4x4;
			for (int i = 0; i < Row; i++)
				for (int j = 0; j < Column; j++)
					Mat4x4.mat[i][j] = 0;
			int i, j;
			for (int r = 0; r < Row; r++)
			{
				for (int c = 0; c < Column; c++)
				{
					for (i = 0, j = 0; i < Column, j < Row; j++, i++)
					{
						Mat4x4.mat[r][c] += mat[r][j] * mat4x4.mat[j][c];
					}
				}
			}
			return Mat4x4;
		}
		bool Matrix4x4::operator==(const Matrix4x4 & mat4x4) const
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Column; j++)
				{
					if (mat[i][j] != mat4x4.mat[i][j])
					{
						return false;
					}
				}
			}
			return true;
		}
		bool Matrix4x4::operator!=(const Matrix4x4 & mat4x4) const
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Column; j++)
				{
					if (mat[i][j] != mat4x4.mat[i][j])
					{
						return true;
					}
				}
			}
			return false;
		}
		void ScalarSinCos(float * pSin, float * pCos, float angle)
		{
			*pCos = cosf(angle);
			*pSin = sinf(angle);
		}
		Matrix4x4 Matrix4x4Identity()
		{
			Matrix4x4 mat4x4;
			memset(mat4x4.mat, 0, sizeof(mat4x4.mat));
			mat4x4.mat[0][0] = 1;
			mat4x4.mat[1][1] = 1;
			mat4x4.mat[2][2] = 1;
			mat4x4.mat[3][3] = 1;
			return mat4x4;
		}
		Matrix4x4 MatrixPerspectiveFovLH(float fovy, float aspect, float near, float far)
		{
			float    SinFov;
			float    CosFov;
			ScalarSinCos(&SinFov, &CosFov, 0.5f * fovy);

			float yScale = CosFov / SinFov;
			float xScale = yScale / aspect;
			float fRange = far / (far - near);

			Matrix4x4 mat4x4;
			mat4x4.mat[0][0] = xScale;
			mat4x4.mat[1][1] = yScale;
			mat4x4.mat[2][2] = fRange;
			mat4x4.mat[2][3] = 1;
			mat4x4.mat[3][2] = -fRange * near;

			return mat4x4;
		}
		Matrix4x4 MatrixLookAtLH(Vector3 eye, Vector3 at, Vector3 up)
		{
			Vector3 axisZ = at - eye;
			Normalize(axisZ);
			Vector3 axisX = up.Cross(axisZ);
			Normalize(axisX);
			Vector3 axisY = axisZ.Cross(axisX);
			Vector3 ngeye = -eye;
			float tx = axisX.Dot(ngeye);
			float ty = axisY.Dot(ngeye);
			float tz = axisZ.Dot(ngeye);
			Matrix4x4 mat4x4;
			mat4x4.mat[0][0] = axisX.x;
			mat4x4.mat[0][1] = axisX.y;
			mat4x4.mat[0][2] = axisX.z;
			mat4x4.mat[0][3] = tx;
			mat4x4.mat[1][0] = axisY.x;
			mat4x4.mat[1][1] = axisY.y;
			mat4x4.mat[1][2] = axisY.z;
			mat4x4.mat[1][3] = ty;
			mat4x4.mat[2][0] = axisZ.x;
			mat4x4.mat[2][1] = axisZ.y;
			mat4x4.mat[2][2] = axisZ.z;
			mat4x4.mat[2][3] = tz;
			mat4x4.mat[3][3] = 1;
			MatrixTranspose(mat4x4);
			return mat4x4;
		}
		void MatrixTranspose(Matrix4x4 & mat4x4)
		{
			float tmp;
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Column; j++)
				{
					if (i <= j)
					{
						continue;
					}
					if (mat4x4.mat[i][j] == mat4x4.mat[j][i])
					{
						continue;
					}
					else
					{
						tmp = mat4x4.mat[j][i];
						mat4x4.mat[j][i] = mat4x4.mat[i][j];
						mat4x4.mat[i][j] = tmp;
					}
				}
			}
		}
		Matrix4x4 MatrixTranslation(float offset_x, float offset_y, float offset_z)
		{
			Matrix4x4 mat4x4;
			mat4x4 = Matrix4x4Identity();
			mat4x4.mat[3][0] = offset_x;
			mat4x4.mat[3][1] = offset_y;
			mat4x4.mat[3][2] = offset_z;
			return mat4x4;
		}
		Matrix4x4 MatrixRotationX(float angle)
		{
			float sin, cos;
			Matrix4x4 mat4x4;
			mat4x4 = Matrix4x4Identity();
			ScalarSinCos(&sin, &cos, angle);
			mat4x4.mat[1][1] = cos;
			mat4x4.mat[1][2] = sin;
			mat4x4.mat[2][1] = -sin;
			mat4x4.mat[2][2] = cos;
			return mat4x4;
		}
		Matrix4x4 MatrixRotationY(float angle)
		{
			float sin, cos;
			Matrix4x4 mat4x4;
			mat4x4 = Matrix4x4Identity();
			ScalarSinCos(&sin, &cos, angle);
			mat4x4.mat[0][0] = cos;
			mat4x4.mat[0][2] = -sin;
			mat4x4.mat[2][0] = sin;
			mat4x4.mat[2][2] = cos;
			return mat4x4;
		}
		Matrix4x4 MatrixRotationZ(float angle)
		{
			float sin, cos;
			Matrix4x4 mat4x4;
			mat4x4 = Matrix4x4Identity();
			ScalarSinCos(&sin, &cos, angle);
			mat4x4.mat[0][0] = cos;
			mat4x4.mat[0][1] = sin;
			mat4x4.mat[1][0] = -sin;
			mat4x4.mat[1][1] = cos;
			return mat4x4;
		}
		Matrix4x4 MatrixScaling(float scale_x, float scale_y, float scale_z)
		{
			Matrix4x4 mat4x4;
			mat4x4 = Matrix4x4Identity();
			mat4x4.mat[0][0] = scale_x;
			mat4x4.mat[1][1] = scale_y;
			mat4x4.mat[2][2] = scale_z;
			return mat4x4;
		}
	}
}