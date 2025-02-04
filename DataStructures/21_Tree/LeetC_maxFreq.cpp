#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void print(const vector<int> &nums){
    for(int x : nums){
        std::cout << x << " ";
    }
    std::cout << endl;
}

class KthLargest {
    int k = -1;
    priority_queue<int> q;
public:
    KthLargest(int k, const vector<int>& nums) : k(k) {
        for(int x : nums){
            q.push(x);
        }
    }
    
    int add(int val) {
        q.push(val);
        
        int res = 0;
        int count = 1;
        vector<int> arr;
        if(k <= q.size()){
            while(q.size() && count < k){
                res = q.top(); q.pop();
                arr.push_back(res); print(arr);
                count++;
            }
        }
        count--;
        while(count >= 0){
            int x = arr[count];
            q.push(arr[count]);
            count--;
        }
        return res;
    }
};

int main()
{
    int val;
    KthLargest kthLargest(4, {7, 7, 7, 7, 8, 3 });
    val = kthLargest.add(2);  // return 7
    val = kthLargest.add(10); // return 7
    val = kthLargest.add(9);  // return 7
    val = kthLargest.add(9);  // return 8

    return 0;
}
