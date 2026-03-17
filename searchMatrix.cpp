//
// Created by A on 2026/3/17.
//
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0;
        int right=m*n-1;
        while (left<=right)
        {
            //divide
            int mid=left+(right-left)/2;
            int row=mid/n;
            int col=mid%n;
            //conquer(decrease)
            if (matrix[row][col]<target)//在右边找，去掉左边
            {
                left=mid+1;
            }
            else if (matrix[row][col]>target)
            {
                right=mid-1;
            }
            else return true;
        }
        return false;
    }
};