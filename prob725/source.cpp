#include <iostream>
#include <vector>

/*
WORK IN PROGRESS!!
there can be at most 10 non zero digits (one 9, nine 1s)
find the combinations that work and do combinations over 2020 pos 
(WITH FIRST N != 0)
*/

using namespace std;

bool valid_set(vector<int> set)
{
    int sum = 0;
    for (int i = 0; i < set.size(); i++)
    {
        sum += set[i];
    }

    for (int i = 0; i < set.size(); i++)
    {
        if ((sum - set[i]) == set[i])
        {
            return true;
        }
    }

    return false;
}

void digit_set_gen_r(vector<int> cand, vector<vector<int>> &sets, int size, int min_ins)
{

    if (cand.size() == size)
    {
        if (valid_set(cand))
        {
            sets.push_back(cand);
        }
        return;
    }

    for (int i = min_ins; i < 10; i++)
    {
        cand.push_back(i);
        digit_set_gen_r(cand, sets, size, i);
        cand.pop_back();
    }
}

void digit_set_gen(vector<vector<int>> &sets)
{
    vector<int> cand;
    for (int i = 2; i <= 10; i++)
    {
        cand.clear();
        digit_set_gen_r(cand, sets, i, 1);
    }
}

int main()
{
    vector<vector<int>> sets = {};
    digit_set_gen(sets);
    for (int i = 0; i < sets.size(); i++)
    {
        cout << "{ ";
        for (int j = 0; j < sets[i].size(); j++)
        {
            cout << sets[i][j] << " ,";
        }
        cout << "}\n";
    }
}