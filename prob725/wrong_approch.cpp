#include <iostream>
#include <string>
#include <bits/stdc++.h>

// keeping this stupid code because there could be some stuff that is reusable,
// even though the approach taken was extremely rushed and not usable for anywhere near the
// required amount of digits. The large_num class could be somewhat reusable.

using namespace std;

class large_num
{
private:
    static const int max_digits = 2020;
    char number[max_digits];
    int n_digits;
    int digit_sum;

public:
    large_num();
    bool plus_one();
    bool is_DS();
    long long int modulo10e16();
};

large_num::large_num()
{
    for (int i = 0; i < max_digits; i++)
    {
        number[i] = '0';
    }

    n_digits = 1;
    digit_sum = 0;
}

//returns false in case of "overflow", true otherwise
bool large_num::plus_one()
{
    char digit;

    for (int i = max_digits - 1; i >= 0; i--)
    {
        digit = number[i];
        if (digit == '9')
        {
            number[i] = '0';
            digit_sum -= 9;
            if (i == max_digits - n_digits)
            {
                n_digits++;
            }
        }
        else
        {
            number[i] += 1;
            digit_sum += 1;
            break;
        }
    }

    return n_digits <= 2020;
}

bool large_num::is_DS()
{

    for (int i = max_digits - n_digits; i < max_digits; i++)
    {
        if ((number[i] - '0') == (digit_sum - (number[i] - '0')))
        {
            return true;
        }
    }

    return false;
}

long long int large_num::modulo10e16()
{
    string num = "";
    for (int i = max_digits - (n_digits < 15 ? n_digits : 15); i < max_digits; i++)
    {
        num.push_back(number[i]);
    }

    return stoll(num, nullptr, 10);
}

int main()
{

    large_num n;
    long long int result = 0;

    while (n.plus_one())
    {
        if (n.is_DS())
        {
            result += n.modulo10e16();
            if (result > 10000000000000000)
            {
                result % stoll("10000000000000000", nullptr, 10);
                cout << "10e16 \n";
            }
        }
    }

    cout << result;
}
