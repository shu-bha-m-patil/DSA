#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<int> &prices)
{
    for (size_t i = 0; i < prices.size(); i++)
        std::cout << prices[i] << " ";
    std::cout << std::endl;
}

int main()
{
    // vector<int> prices = {2,1,2,0,1};
    // if (prices.size() == 1)
    //     return 0;
    // vector<int> minPricesInd;
    // vector<int> maxPricesInd;
    // for (int i = 0; i < prices.size() - 1; ++i)
    // {
    //     if (prices[i] < prices[i + 1])
    //     {
    //         minPricesInd.emplace_back(prices[i]);
    //         maxPricesInd.emplace_back(prices[i + 1]);
    //     }
    // }

    // print(minPricesInd);
    // print(maxPricesInd);
    // int maxProfit = 0;
    // for (int iMin = 0; iMin < minPricesInd.size(); ++iMin)
    // {
    //     for (int iMax = iMin; iMax < maxPricesInd.size(); ++iMax)
    //     {
    //         maxProfit = std::max(maxProfit, maxPricesInd[iMax] - minPricesInd[iMin]);
    //     }
    // }
    // return maxProfit;

    vector<int> prices = {2,1,2,0,1};
        if (prices.size() == 1)
            return 0;

    int lsf = INT_MAX; // least so far
        int op = 0; // overall profit
        int pist = 0; // profit if sold today
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < lsf){ // if we found new buy value which is more smaller then previous one
                lsf = prices[i]; // update our least so far
            }
            pist = prices[i] - lsf; // calculating profit if sold today by, Buy - sell
            if(op < pist){ // if pist is more then our previous overall profit
                op = pist; // update overall profit
            }
        }
        return op; // re
}
