#include <iostream>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> map;
    for (char c : s)
    {
        map[c]++;
    }

    for (int i = 0; i < s.size(); ++i)
    {
        auto it = map.find(s[i]);
        if (it->second == 1)
            return i;
    }
    return -1;
}

int main()
{
    int ind = firstUniqChar("loveleetcode");
    return 0;
}