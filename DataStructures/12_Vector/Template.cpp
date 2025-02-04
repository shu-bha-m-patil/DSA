#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;


int timeRequiredToBuy(vector<int>& tickets, int k) {
        std::queue<std::pair<int,int>>q;
        int i = 0;
        for(int &x : tickets){
            q.push({i,x});
            i++;
        }
        int noOfsec = 0;
        std::pair<int,int> p;
        while(p.first != k || p.second != 0){
            p = q.front(); q.pop();
            if(p.second){
                p.second--;
                noOfsec++;
                if(p.second)
                    q.push(p);
            }
        }
        return noOfsec;
    }

 int main()
 {
     std::vector<int> vect = {5,1,1,1};
     int sec = timeRequiredToBuy(vect,0);
     std::cout << sec << std::endl;
     return 0;
 }
