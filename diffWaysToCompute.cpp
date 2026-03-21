#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];

            // 只要遇到运算符，就在这里一刀劈开！
            if (c == '+' || c == '-' || c == '*') {
                // Divide (切分胶布)
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                // Conquer (召唤克隆人)
                vector<int> left_res = diffWaysToCompute(left);
                vector<int> right_res = diffWaysToCompute(right);

                // Combine (双层for循环，平行宇宙合并)
                for (int left_val : left_res) {
                    for (int right_val : right_res) {
                        switch (c) {
                        case '+': res.push_back(left_val + right_val); break;
                        case '-': res.push_back(left_val - right_val); break;
                        case '*': res.push_back(left_val * right_val); break; // 修复了你的笔误
                        }
                    }
                }
            }
        }

        // 老板的顿悟：如果扫完了都没切过，说明是纯数字 Base Case！
        if (res.empty()) {
            res.push_back(stoi(expression));
        }

        return res;
    }
};

int main() {
    Solution sol;
    // 使用一个极其经典的短句，方便我们跟踪
    string expr = "2*3-4";

    cout << "开始解析表达式: " << expr << endl;
    vector<int> result = sol.diffWaysToCompute(expr);

    cout << "所有可能的计算结果为: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}