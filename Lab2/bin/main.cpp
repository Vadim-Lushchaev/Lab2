#include <iostream>
#include "../lib/number.h"

using namespace std;

int main()
{
    uint2022_t num1, num2, res;
    //num1 = from_uint(257);
    num1 = from_uint(33);
    num2 = from_string("6747564776826987624985764875689234765987234659872346587658");
    res = num2 + num1;

    //cout << num1.position << '\n';
    cout << num1 << '\n';

    //cout << num2.position << '\n';
    cout << num2 << '\n';

    //cout << res.position << '\n';
    cout << res;
    return 0;
}