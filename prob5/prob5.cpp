#include <iostream>

/*
bruteforce is enough for this easy ones, using cpp it's almost instantaneous 
*/

using namespace std;

int main()
{
    int val;

    for (int i = 2520; true; i++)
    {
        bool res = true;
        for (int j = 2; j <= 20; j++)
        {
            if (i % j != 0)
            {
                res = false;
                break;
            }
        }
        if (res)
        {
            val = i;
            break;
        }
    }

    cout << val;
}