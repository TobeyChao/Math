#include <DirectXMath.h>

#include "../3DMath/Vector3.h"
#include "../3DMath/Matrix4x4.h"

#ifdef _DEBUG
#pragma comment(lib, "../bin/3DMath/Debug/3DMath_d.lib")
#else
#pragma comment(lib, "../bin/3DMath/Release/3DMath.lib")
#endif

using namespace Soul;
using namespace Core;

int main(int argc, char* argv[])
{
	//Vector
    Vector3 vec3_1(0.0f, 0.0f, 1.0f);
    Vector3 vec3_2 = vec3_1;
	Vector3 newvec(1.0f, 0.0f, 1.0f);
	std::cout << &vec3_1 << " " << &vec3_2;
	vec3_2 = vec3_1;
	std::cout << &vec3_1 << " " << &vec3_2;
	//cross
	Vector3 vec3_3 = Cross(vec3_1, vec3_2);
	std::cout << "Cross" << vec3_3 << std::endl;

	//normalize
	vec3_1.Normalize();
	Normalize(vec3_2);
	newvec = vec3_1 + vec3_2;
	std::cout << vec3_1 << std::endl;
	std::cout << vec3_2 << std::endl;
	std::cout << newvec << std::endl;

	//magnitude
	std::cout << vec3_1.Magnitude() << std::endl;

	//operator!=
    if(vec3_1 != vec3_2)
		std::cout << "Dont Match!" << std::endl;

	Matrix4x4 mat1;
	Matrix4x4 mat2;
	Matrix4x4 mat3;
	mat1 = Matrix4x4Identity();
	std::cout << mat1;

	mat2 = MatrixTranslation(10.0f, 20.0f, 30.0f);
	std::cout << mat2;

	mat1 += mat2;
	mat3 = mat1 * mat1;
	std::cout << mat3;

	Matrix4x4 mat4;
	mat4 = Matrix4x4Identity();
	mat4.mat[1][0] = 2.0;
	mat4.mat[2][0] = 3.0;
	mat4.mat[3][0] = 4.0;
	std::cout << mat4;
	MatrixTranspose(mat4);
	std::cout << mat4;

	Vector3 eye(0.0f, 0.0f, -5.0f);
	Vector3 at(0.0f, 0.0f, 0.0f);
	Vector3 up(0.0f, 1.0f, 0.0f);
	Matrix4x4 view = MatrixLookAtLH(eye, at, up);
	std::cout << view;

	Matrix4x4 proj = MatrixPerspectiveFovLH(SM_PIDIV2, 800.0f / 600.0f, 1.0f, 1000.0f);
	std::cout << proj;


	DirectX::XMVECTOR m_position = DirectX::XMVectorSet(0.0f, 0.0f, -5.0f, 0.0f);
	DirectX::XMVECTOR m_target = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	DirectX::XMVECTOR m_up = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	DirectX::XMMATRIX mamt = DirectX::XMMatrixLookAtLH(m_position, m_target, m_up);
	DirectX::XMMATRIX dproj = DirectX::XMMatrixPerspectiveFovLH(DirectX::XM_PIDIV2, 800.0f / 600.0f, 1.0f, 1000.0f);

	system("pause");
    return 0;
}