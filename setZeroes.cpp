//
// Created by A on 2026/4/2.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        bool row0_has_zero=false,col0_has_zero=false;
        for (int i=0;i<cols;i++)
        {
            if (matrix[0][i]==0)
            {
                row0_has_zero=true;
                break;
            }
        }
        for (int j=0;j<rows;j++)
        {
            if (matrix[j][0]==0)
            {
                col0_has_zero=true;
                break;
            }
        }
        for (int i=1;i<rows;i++)
        {
            for (int j=1;j<cols;j++)
            {
                if (matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for (int i=1;i<rows;i++)
        {
            for (int j=1;j<cols;j++)
            {
                if (matrix[0][j]==0||matrix[i][0]==0) matrix[i][j]=0;
            }
        }
        if (col0_has_zero)
        {
            for (int i=0;i<rows;i++)
            {
                matrix[i][0]=0;
            }
        }
        if (row0_has_zero)
        {
            for (int i=0;i<cols;i++)
            {
                matrix[0][i]=0;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    sol.setZeroes(matrix);

    for (const auto& row : matrix)
    {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}
