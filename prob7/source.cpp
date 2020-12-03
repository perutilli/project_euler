#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int N = 10001;

bool is_prime(int, vector<int>);

int main()
{

    vector<int> primes;

    //pretty inefficient
    for (int i = 2; true; i++)
    {
        if (is_prime(i, primes))
        {
            primes.push_back(i);
            if (primes.size() == N)
            {
                cout << primes[N - 1];
                break;
            }
        }
    }
}

bool is_prime(int num, vector<int> prev_primes)
{

    int max_factor = sqrt(num);

    for (int p : prev_primes)
    {
        if ((num % p) == 0)
        {
            return false;
        }

        if (p > max_factor)
        {
            break;
        }
    }

    return true;
}