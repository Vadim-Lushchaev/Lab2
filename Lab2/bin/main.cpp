#include <iostream>
#include "../lib/number.h"

using namespace std;

int main()
{
    uint2022_t num1, num2, res;
    num1 = from_uint(999999);
    num2 = from_string("999999");

    cout << "NUM1: " << num1 << '\n';
    cout << "NUM2: " << num2 << '\n';
    res = num1 + num2;
    cout << "NUM1 + NUM2 = " << res << '\n';
    res = num1 - num2;
    cout << "NUM1 - NUM2 = " << res << '\n';
    res = num1 * num2;
    cout << "NUM1 * NUM2 = " << res << '\n';

    if (num1 == num2)
    {
        cout << "num1 = num2" << '\n';
    }
    if (num1 != num2)
    {
        cout << "num1 != num2" << '\n';
    }
    if (num1 == res)
    {
        cout << "num1 = res" << '\n';
    }
    if (num1 != res)
    {
        cout << "num1 != res" << '\n';
    }
    if (num2 == res)
    {
        cout << "num1 = res" << '\n';
    }
    if (num2 != res)
    {
        cout << "num1 != res" << '\n';
    }

    return 0;
}