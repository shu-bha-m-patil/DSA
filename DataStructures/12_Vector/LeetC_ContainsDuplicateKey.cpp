#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void  print(vector<int> &prices)
{
    for (size_t i = 0; i < prices.size(); i++)
        std::cout << prices[i] << " ";
    std::cout << std::endl;
}


bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<int>vect;
        for(int i = 0; i < nums.size(); ++i){
            auto it = std::find(vect.begin(), vect.end(), nums[i]);
            if(it != vect.end()){
                int firstPos = it - vect.begin();
                if((i - firstPos) <= k)
                    return true;
                else{
                    //vect[firstPos] = INT_MAX;   print(vect);
                    vect.emplace_back(nums[i]);
                }
            }
            else{
                vect.emplace_back(nums[i]);
            }

        }
        return false;
    }

int main(){
    vector<int> nums = {1,0,1,1};
    containsNearbyDuplicate(nums, 1);
    return 0;
}