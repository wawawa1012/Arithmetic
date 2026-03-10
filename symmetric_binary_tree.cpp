#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // 这是一个构造函数，方便我们一行代码创建节点
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
private:
    bool check(TreeNode* p, TreeNode* q)
    {
        if (p==nullptr&&q==nullptr) return true;
        if (p==nullptr&&q!=nullptr) return false;
        if (p!=nullptr&&q==nullptr) return false;
        if (p->val!=q->val) return false;
        return check(p->left, q->right) && check(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr) return true;
        if (check(root->left,root->right)) return true;
        return false;
    }
};
int main() {
    // 挑战：手动建造一棵长这样的对称树：
    //       1
    //     /   \
    //    2     2
    //   / \   / \
    //  3   4 4   3

    // 第一步：用 new 创造出一个个孤立的节点 (砖块)
    TreeNode* root = new TreeNode(1);

    TreeNode* left_child = new TreeNode(2);
    TreeNode* right_child = new TreeNode(2);

    TreeNode* ll = new TreeNode(3);
    TreeNode* lr = new TreeNode(4);

    TreeNode* rl = new TreeNode(4);
    TreeNode* rr = new TreeNode(3);

    // 第二步：用指针把它们像绳子一样连起来 (砌墙)
    root->left = left_child;
    root->right = right_child;

    left_child->left = ll;
    left_child->right = lr;

    right_child->left = rl;
    right_child->right = rr;

    // 第三步：召唤你的核心算法！
    Solution s;
    bool result = s.isSymmetric(root);

    if (result) {
        cout << "测试成功！这是一棵对称的二叉树！" << endl;
    } else {
        cout << "测试失败！这棵树不对称！" << endl;
    }

    // (规范做法：测试完了记得用 delete 把 new 出来的内存释放掉，这里为了精简就省略了)
    return 0;
}
