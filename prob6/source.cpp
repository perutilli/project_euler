#include <iostream>

using namespace std;

const int N = 100;

int main()
{

    int sq_of_sum = 0, sum_of_sq = 0;
    for (int i = 1; i < N + 1; i++)
    {
        sum_of_sq += i * i;
    }

    sq_of_sum = (N * N * (N + 1) * (N + 1)) / 4;

    cout << sq_of_sum - sum_of_sq;
}