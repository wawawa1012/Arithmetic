//
// Created by A on 2026/3/20.
//
#include <vector>
#include <unordered_map>
using namespace std;

// 树节点的定义 (不用你写，系统自带)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // 为了让老板瞬间在中序遍历里找到老大的位置，建一个账本！
    unordered_map<int, int> indexMap;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 1. 登记账本：把 inorder 里的 [数字 -> 下标] 存起来，方便 O(1) 查找
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }

        // 2. 召唤克隆人开始分治！
        // 传入的是 preorder 和 inorder 的起始与结束下标
        return myBuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder,
                          int preorder_left, int preorder_right,
                          int inorder_left, int inorder_right) {

        // Base Case：如果包围圈里一个人都没了（越界了），说明是空树
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        // 第一步：根据前序遍历找老大，并直接 new 出这个节点
        // 填空... TreeNode* root = ...
        TreeNode* root=new TreeNode(preorder[preorder_left]);
        // 第二步：查账本，看看老大在中序遍历里的位置 (inorder_root)
        // 填空... int inorder_root = ...
        int inorder_root = indexMap[root->val];
        // 第三步：算出左子树一共分到了几个人？(size_left_subtree)
        // 提示：用老大在中序里的位置，减去中序的左边界
        // 填空... int size_left_subtree = ...
        int left_size=inorder_root-inorder_left;
        // 第四步：派克隆人组装左子树和右子树！(最考验边界的一步)
        // root->left = myBuildTree(preorder, inorder, 新的前序左, 新的前序右, 新的中序左, 新的中序右);
        // root->right = myBuildTree(...);
        root->left=myBuildTree(preorder,inorder,
            preorder_left+1,preorder_left+left_size,
            inorder_left,inorder_root-1);
        root->right=myBuildTree(preorder,inorder,
            preorder_left+left_size+1,preorder_right,
            inorder_root+1,inorder_right);
        return root;
    }
};