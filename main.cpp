#include "Vector3.h"
using namespace std;

int main()
{
    Vector3 vec3_1(1.5f, 1.2f, 1.1f);
    Vector3 vec3_2(1.5f, 1.2f, 1.1f);
    bool x = vec3_1 != vec3_2;
    cout << !x << endl;
    return 0;
}
