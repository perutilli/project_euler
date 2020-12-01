#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(int);

int main()
{

    int prod, max_prod = -1;

    for (int i = 100; i < 1000; i++)
    {
        for (int j = i; j < 1000; j++)
        {
            prod = i * j;
            if ((prod > max_prod) && is_palindrome(prod))
            {
                max_prod = prod;
            }
        }
    }

    cout << max_prod;

    return 0;
}

bool is_palindrome(int num)
{
    string s = to_string(num);
    int len = s.length();

    for (int i = 0; i < (len + 1) / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return false;
        }
    }

    return true;
}