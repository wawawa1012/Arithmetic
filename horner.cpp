//
// Created by A on 2026/4/8.
//
#include <iostream>
#include <vector>
//霍纳法则是一个减少乘法次数的简化算法，可以通过提取公因式将多项式乘法次数降低到最高次幂的次数
using namespace std;

class Solution {
public:
    int evaluatePolynomial(vector<int>& coeffs, int x) {
        int res=coeffs[0];
        for (int i=1;i<coeffs.size();i++)
        {
            res=res*x+coeffs[i]; //$n$ 次多项式”（比如最高次幂是 $x^3$），那么它的乘法次数就是极其严格的 $n$ 次！
        }
        return res;
    }
};

int main() {
    Solution sol;

    // 代表多项式: 2x^3 - 6x^2 + 2x - 1, 代入 x = 3
    vector<int> coeffs1 = {2, -6, 2, -1};
    cout << "测试 1 (预期 5): " << sol.evaluatePolynomial(coeffs1, 3) << endl;

    // 代表多项式: 1x^2 + 2x + 3, 代入 x = 2
    vector<int> coeffs2 = {1, 2, 3};
    cout << "测试 2 (预期 11): " << sol.evaluatePolynomial(coeffs2, 2) << endl;

    return 0;
}