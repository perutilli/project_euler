#include <iostream>

int main()
{
    int sum = 0;
    int a = 1, b = 1, temp;

    while (a + b <= 4000000)
    {
        temp = a + b;
        if (temp % 2 == 0)
        {
            sum += temp;
        }
        a = b;
        b = temp;
    }

    std::cout << sum;
}