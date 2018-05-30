#ifndef VECTOR3_H
#define VECTOR3_H
#include <iostream>

class Vector3
{
    public:
        Vector3();
        Vector3(float in_x, float in_y, float in_z);
        Vector3(const Vector3& vec3);
        virtual ~Vector3();
        float magnitude() const;
        void normalize();
        float dot(const Vector3 &vec3);
        Vector3 cross(const Vector3 &vec3);
        friend std::ostream &operator<<( std::ostream &output, const Vector3 &vec3);
        //Operators
        Vector3 operator+(const Vector3 &v) const;
        Vector3 operator-(const Vector3 &v) const;
        Vector3 operator*(float num) const;
        Vector3 operator/(float num) const;
        Vector3 &operator+=(const Vector3 &v);
        Vector3 &operator-=(const Vector3 &v);
        Vector3 &operator*=(float num);
        Vector3 &operator/=(float num);
        //Returns true if vectors different.
        bool operator!=(Vector3 &v) const;
    protected:

    private:
        float x;
        float y;
        float z;
};

#endif // VECTOR3_H
