//
// Created by A on 2026/4/3.
//
#include <iostream>
#include <vector>
#include <iomanip> // 用于对齐输出

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int left=0,right=n-1;
        int up=0,down=n-1;
        int count=1;
        while (left<=right&&up<=down)
        {
            for (int i=left;i<=right;i++)
            {
                res[up][i]=count;
                count++;
            }
            up++;
            for (int i=up;i<=down;i++)
            {
                res[i][right]=count;
                count++;
            }
            right--;
            for (int i=right;i>=left;i--)
            {
                res[down][i]=count;
                count++;
            }
            down--;
            for (int i=down;i>=up;i--)
            {
                res[i][left]=count;
                count++;
            }
            left++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> matrix = sol.generateMatrix(n);

    cout << "生成的 " << n << "x" << n << " 螺旋矩阵:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}