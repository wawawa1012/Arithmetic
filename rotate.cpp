//
// Created by A on 2026/4/2.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int i=0;i<n/2;i++)//水平对称
        {
            for (int j=0;j<n;j++)
            {
                swap(matrix[i][j],matrix[n-i-1][j]);
            }
        }
        for (int i=0;i<n;i++)//对角线对称
        {
            for (int j=0;j<n-i-1;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    sol.rotate(matrix);

    cout << "旋转后的图像：" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
