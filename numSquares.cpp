//
// Created by A on 2026/3/24.
//
//a可以由b+某个完全平方数得到，b又可以由更小数+完全平方数。并且最坏情况每个数都可以+1得到其他。
//也是从前往后的斐波那契型题目，像建房子一般不能回头，可以选择使用DP
//n为1-10000，所以最夸张也只可能是100的平方,严谨起见，我选择对n开根

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,n+1); //初始化为极大值
        dp[0]=0;//base case，虽然题目给了n不可能为0
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j * j <= i;j++)
            {
                if (i>=j*j) dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n]>n?-1:dp[n];
    }
};

int main()
{
    Solution s;
    cout<<s.numSquares(13);
}