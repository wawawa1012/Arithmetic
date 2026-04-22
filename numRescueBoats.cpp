//
// Created by A on 2026/4/22.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //排序
        sort(people.begin(),people.end());
        //两个指针分别指向最胖和最瘦的
        int thinnest=0,fattest=people.size()-1;
        int boat=0;
        while (thinnest<=fattest)
        {
            if (people[thinnest]+people[fattest]<=limit) thinnest++;
            fattest--;
            boat++;
        }
        // 4. 返回最终战果
        return boat;
    }
};