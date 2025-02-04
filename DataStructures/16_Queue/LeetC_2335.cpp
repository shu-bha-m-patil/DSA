#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

std::function<bool(int *, int *)> cmpS = [](int *a, int *b)
{ return *a < *b; };
std::function<bool(int *, int *)> cmpG = [](int *a, int *b)
{ return *a > *b; };

int fillCups(const vector<int> &amount)
{
    priority_queue<int> q;
    for (int x : amount)
    {
        q.push(x);
    }

    int sec = 0;
    while (q.size())
    {
        int x = q.top();
        q.pop();
        --x;
        if (q.size() == 2)
        {
            int y = q.top();
            q.pop();
            int z = q.top();
            q.pop();
            --z;
            if (z > 0)
            {
                q.push(z);
            }
            q.push(y);
        }
        else if (q.size() == 1)
        {
            int y = q.top();
            q.pop();
            --y;
            if (y > 0)
            {
                q.push(y);
            }
        }
        if (x > 0)
        {
            q.push(x);
        }
        if(x >= 0)
        ++sec;
    }
    return sec;
}

int main()
{
    fillCups({0,2,2});
    return 0;
}