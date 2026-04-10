//
// Created by A on 2026/4/10.
//
#include <iostream>
#include <algorithm> // 为了使用 swap

using namespace std;

// 极其经典的二叉树节点定义
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        //base case
        if (root==nullptr) return nullptr;
        //交换
        swap(root->left,root->right);
        //recursive
        root->left=invertTree(root->left);
        root->right=invertTree(root->right);
        return root;
    }
};

// 后面的 main 函数测试代码比较长（需要建树），你只需要专注完成 invertTree 的逻辑即可！
