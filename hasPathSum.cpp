//
// Created by A on 2026/4/25.
//
#include <iostream>

using namespace std;

// 极其经典的二叉树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 1. 如果节点为空，直接没戏
        if (root==nullptr) return false;
        // 2. 如果是叶子节点，判断当前的值是不是刚好等于剩下的 targetSum
        if (root->left==nullptr&&root->right==nullptr) return root->val==targetSum;
        // 3. 甩锅环节：看左子树或者右子树能不能搞定剩下的额度
        bool l = hasPathSum(root->left, targetSum - root->val);
        bool r = hasPathSum(root->right, targetSum - root->val);
        return l||r;
    }
};

// ======= 大老板的后勤车间 (不要动，直接运行) =======
int main() {
    Solution sol;

    // 测试用例 1：一条完美的通路
    //       5
    //      / \
    //     4   8
    //    /   / \
    //   11  13  4
    //  /  \      \
    // 7    2      1
    // 目标 22，应该返回 true (5 -> 4 -> 11 -> 2)
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(11);
    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(13);
    root1->right->right = new TreeNode(4);
    root1->right->right->right = new TreeNode(1);

    cout << "战报 1: 寻找能量 22 -> "
         << (sol.hasPathSum(root1, 22) ? "成功! (预期: 成功)" : "失败! (预期: 成功)") << endl;

    // 测试用例 2：看似能成，实则扑空 (因为不是叶子节点)
    //   1
    //  / \
    // 2   3
    // 目标 1，应该返回 false (虽然根节点就是1，但路径必须走到叶子节点才算完结！)
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << "战报 2: 寻找能量 1 -> "
         << (sol.hasPathSum(root2, 1) ? "成功! (预期: 失败)" : "失败! (预期: 失败)") << endl;

    // 测试用例 3：空树
    TreeNode* root3 = NULL;
    cout << "战报 3: 寻找能量 0 -> "
         << (sol.hasPathSum(root3, 0) ? "成功! (预期: 失败)" : "失败! (预期: 失败)") << endl;

    return 0;
}