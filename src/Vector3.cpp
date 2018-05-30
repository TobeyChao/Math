#include "Vector3.h"

Vector3::Vector3()
{
    //ctor
}

Vector3::~Vector3()
{
    //dtor
}
Vector3::Vector3(float in_x, float in_y, float in_z)
:
    x(in_x),
    y(in_y),
    z(in_z)
{
}
Vector3::Vector3(const Vector3& vec3)
{
    x = vec3.x;
    y = vec3.y;
    z = vec3.z;
}
std::ostream &operator<<( std::ostream &output, const Vector3 &vec3 )
{
    output << "X: " << vec3.x << " Y: " << vec3.y << " Z: " << vec3.z;
    return output;
}
