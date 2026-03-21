//
// Created by A on 2026/3/21.
//
#include <math.h>
#include <vector>
using namespace std;

// 树节点的定义
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};

class Solution
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return dfs(nums,0,nums.size()-1);
    }

private:
    TreeNode* dfs(vector<int>& nums, int left, int right)
    {
        //base case
        if (left>right) return nullptr;
        //divide
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        //conquer
        root->left = dfs(nums, left, mid - 1);
        root->right = dfs(nums, mid + 1, right);
        //combine
        return root;
    }
};
