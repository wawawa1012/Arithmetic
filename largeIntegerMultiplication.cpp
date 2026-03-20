//
// Created by A on 2026/3/20.
//
#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long karatsuba(long long num1, long long num2)
    {
        // 1. Base case
        if (num1 < 10 || num2 < 10)
        {
            return num1 * num2;
        }

        // 2. 算位数
        int digit1 = 0, digit2 = 0;
        long long temp1 = num1, temp2 = num2; // 必须用 long long 接管！
        while (temp1 > 0)
        {
            digit1++;
            temp1 /= 10;
        }
        while (temp2 > 0)
        {
            digit2++;
            temp2 /= 10;
        }
        int m = max(digit1, digit2) / 2; // 找到劈开的位置 (一半)

        // 3. Divide (切分)
        long long d = (long long)pow(10, m);
        long long high1 = num1 / d;
        long long low1 = num1 % d;
        long long high2 = num2 / d;
        long long low2 = num2 % d;

        // 4. Conquer (召唤 3 个克隆人)
        long long z2 = karatsuba(high1, high2);
        long long z0 = karatsuba(low1, low2);
        long long z1 = karatsuba(high1 + low1, high2 + low2);

        // 5. Combine (老板合并交差)
        long long res=z2*(long long)pow(10,2*m)+(z1-z2-z0)*(long long)pow(10,m)+z0;
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.karatsuba(158695659,494945767);
}
