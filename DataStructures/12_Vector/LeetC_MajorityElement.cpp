#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {3,3,4};

    if (nums.size() == 1)
        return nums[0];
    std::sort(nums.begin(), nums.end());

    int count = 1;
    int maxCount = 1;
    int maxCountElem = INT_MAX;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (nums[i] != nums[i + 1])
        {
            if (maxCount <= count)
            {
                maxCountElem = nums[i];
                maxCount = count;
            }
            count = 1;
        }
        else
        {
            count++;
        }

        if (maxCount < count)
        {
            return nums[nums.size() - 1];
        }
    }
    return maxCountElem;
}
