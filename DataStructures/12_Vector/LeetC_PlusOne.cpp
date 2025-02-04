#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


void print(vector<int> vect)
{
    for(int x : vect)
    {
        std::cout << x << ", ";
    }
        std::cout << std::endl;
}

vector<int> plusOne(vector<int> &digits)
{
    int li = digits.size() - 1;
    if (digits[li] < 9)
        digits[li]++;
    else
    {
        int noOfNine = 0;
        while (-1 < li && digits[li] == 9)
        {
            li--;
            noOfNine++;
        }

        if (-1 < li)
        {
            digits[li]++; print(digits);
            digits.erase(digits.begin() + li + 1, digits.end()); print(digits);
            digits.insert(digits.begin() + li + 1, noOfNine, 0); print(digits);
        }
        else
        {
            digits.clear();
            digits.emplace_back(1);
            digits.insert(digits.begin(), noOfNine, 0);
        }
    }
    return digits;
}

int main()
{
    vector<int> vect = {8,9,9,9};
    vect = plusOne(vect);
    print(vect);
}