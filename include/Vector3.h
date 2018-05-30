#ifndef VECTOR3_H
#define VECTOR3_H
#include <iostream>
using namespace std;
class Vector3
{
    public:
        Vector3();
        Vector3(float in_x, float in_y, float in_z);
        Vector3(const Vector3& vec3);
        virtual ~Vector3();
        friend std::ostream &operator<<( std::ostream &output, const Vector3 &vec3);

    protected:

    private:
        float x;
        float y;
        float z;
};

#endif // VECTOR3_H
