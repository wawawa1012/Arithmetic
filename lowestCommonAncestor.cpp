//
// Created by A on 2026/3/22.
//

//Definition for a binary tree node.
#include <iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (root==nullptr) return nullptr;
        if (root->val==p->val||root->val==q->val) return root;
        //divide and conquer
        TreeNode* left_ans=lowestCommonAncestor(root->left,p,q);
        TreeNode* right_ans=lowestCommonAncestor(root->right,p,q);
        // Combine（简化法）
        if (left_ans == nullptr) return right_ans;
        if (right_ans == nullptr) return left_ans;
        return root;
    }
};
int main() {
    // 手工搭一棵小树:
    //       3
    //      / \
    //     5   1
    TreeNode* root = new TreeNode(3);
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);
    root->left = p;
    root->right = q;

    Solution sol;
    TreeNode* ancestor = sol.lowestCommonAncestor(root, p, q);

    if (ancestor) {
        cout << "最近公共祖先是: " << ancestor->val << endl; // 预期输出 3
    }

    return 0;
}