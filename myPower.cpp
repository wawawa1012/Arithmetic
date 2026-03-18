//
// Created by A on 2026/3/18.
//
#include <iostream>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        // 使用 long long 防止 n = -2147483648 时取反溢出
        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return fastPow(x, N);
    }
private:
    // 递归分治函数
    double fastPow(double x, long long n) {
        // 1. Base case：任何数的 0 次方都是 1.0
        if (n == 0) {
            return 1.0;
        }

        // 2. 切分 (Divide) 与 派克隆人干活 (Conquer)
        // 让克隆人去算 x 的 n/2 次方，并把结果拿回来 (记为 half)
        double half=fastPow(x,n/2);

        // 3. 老板合并 (Combine)
        // 如果 n 是偶数，结果就是 half * half
        // 如果 n 是奇数，结果就是 half * half * x
        if (n%2==0) return half*half;
        else return half*half*x;
    }
};