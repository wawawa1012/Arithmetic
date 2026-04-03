//
// Created by A on 2026/4/3.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<int> res;
        //设置四个边界
        int left=0,right=cols-1;
        int up=0,down=rows-1;
        while (left<=right&&up<=down)
        {
            for (int i=left;i<=right;i++) //横
            {
                res.push_back(matrix[up][i]);
            }
            up++;
            for (int i=up;i<=down;i++) //竖
            {
                res.push_back(matrix[i][right]);
            }
            right--;
            if (up > down || left > right) {
                break;
            }
            for (int i=right;i>=left;i--)
            {
                res.push_back(matrix[down][i]);
            }
            down--;
            for (int i=down;i>=up;i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    vector<int> res = sol.spiralOrder(matrix);

    cout << "无人机探索路径: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl; // 预期: 1 2 3 4 8 12 11 10 9 5 6 7

    return 0;
}