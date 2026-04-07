//
// Created by A on 2026/4/7.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        //预排序所有的气球，最右端从小到大排序，往极右边缘射可以向左辐射最多
        sort(points.begin(),points.end(),[](vector<int> a,vector<int> b)
        {
            return a[1]<b[1];
        });
        int arrows=1;
        int curr_pos=points[0][1];
        for (int i=1;i<points.size();i++)
        {
            if (points[i][0]>curr_pos)//没有重叠
            {
                curr_pos=points[i][1];
                arrows++;
            }
        }
        return arrows;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> p1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << "测试 1 (预期 2): " << sol.findMinArrowShots(p1) << endl;

    vector<vector<int>> p2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << "测试 2 (预期 4): " << sol.findMinArrowShots(p2) << endl;

    vector<vector<int>> p3 = {{1, 2}, {2, 3}};
    cout << "测试 3 (预期 1, 边缘碰到也算爆!): " << sol.findMinArrowShots(p3) << endl;

    return 0;
}