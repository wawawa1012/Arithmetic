//
// Created by A on 2026/4/21.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res=0,i=0;
        while (res<g.size()&&i<s.size())
        {
            if (g[res]<=s[i]) res++;
            i++;
        }
        return res;
    }
};