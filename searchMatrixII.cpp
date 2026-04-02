//
// Created by A on 2026/4/2.
//
#include <iostream>
#include <vector>
//gemini 的提示已经足够清楚了，应该从右上或左下开始，那么才可以实现明确的降维
//如果在左上方，遇到target大于当前元素会出现两难，一个问题会扩展成两个
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //从右上开始
        int rows=matrix.size(),cols=matrix[0].size();
        int currRow=0,currCol=cols-1;
        while (currCol>=0&&currRow<rows)
        {
            if (matrix[currRow][currCol]==target) return true;
            if (matrix[currRow][currCol]>target) currCol-=1;
            else currRow+=1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    cout << "目标 5 是否存在: " << (sol.searchMatrix(matrix, 5) ? "True" : "False") << endl; // 预期 True
    cout << "目标 20 是否存在: " << (sol.searchMatrix(matrix, 20) ? "True" : "False") << endl; // 预期 False

    return 0;
}