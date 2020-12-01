#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

const long long NUM = 600851475143;

using namespace std;

bool multiple_of_factor(vector<int>, int);

int main()
{
    int max = 0;
    int max_fact = sqrt(NUM);
    vector<int> prime_factors;

    for (int i = 2; i <= max_fact; i++)
    {
        if ((NUM % i == 0) && !(multiple_of_factor(prime_factors, i)))
        {
            prime_factors.push_back(i);
            max = i;
        }
    }
    std::cout << max;

    return 0;
}

bool multiple_of_factor(vector<int> prime_factors, int num)
{

    for (int f : prime_factors)
    {
        if ((num % f) == 0)
        {
            return true;
        }
    }

    return false;
}