//
// Created by A on 2026/4/13.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> count(26, 0);
        for (char c : s)
        {
            count[c - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (count[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
