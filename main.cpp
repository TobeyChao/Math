#include "Vector3.h"
using namespace std;

int main()
{
    Vector3 vec3_1(1.0f, 0.0f, 0.0f);
    Vector3 vec3_2(0.0f, 0.0f, 1.0f);
    //vec3_1.normalize();
    //cout << vec3_1.magnitude() << endl;
    //bool x = vec3_1 != vec3_2;
    //cout << !x << endl;
    Vector3 vec3_3 = vec3_1.cross(vec3_2);
    cout << vec3_3 << endl;
    return 0;
}
