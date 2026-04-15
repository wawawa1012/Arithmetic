//
// Created by A on 2026/4/15.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> tCount(128, 0); // 直接开128，极其稳健，不用考虑大小写偏移
        for (char c : t) tCount[c]++;

        // 关键特务：统计 t 中到底有多少种不同的字母
        int required = 0;
        for (int i = 0; i < 128; i++) if (tCount[i] > 0) required++;

        vector<int> sCount(128, 0);
        int left = 0, right = 0;
        int formed = 0; // 满足了多少种字母的需求
        int min_size = INT_MAX;
        int best_left = 0; // 必须要记下这个！

        while (right < s.size()) {
            char c = s[right];
            sCount[c]++;
            // 只有当数量“刚好”达标时，才给总进度 +1
            if (tCount[c] > 0 && sCount[c] == tCount[c]) {
                formed++;
            }

            // 当进度全满，开始极其疯狂地压榨左边界
            while (formed == required) {
                // 1. 先更新结果
                if (right - left + 1 < min_size) {
                    min_size = right - left + 1;
                    best_left = left;
                }

                char leftChar = s[left];
                sCount[leftChar]--;
                // 如果踢走的是关键核心，且导致数量不足了，进度条倒退
                if (tCount[leftChar] > 0 && sCount[leftChar] < tCount[leftChar]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return min_size == INT_MAX ? "" : s.substr(best_left, min_size);
    }
};