//
// Created by A on 2026/3/25.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for (int i=1;i<=n1;i++)
        {
            for (int j=1;j<=n2;j++)
            {
                if (text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    Solution sol;
    string text1 = "abcde";
    string text2 = "ace";

    int result = sol.longestCommonSubsequence(text1, text2);
    cout << "最长公共子序列的长度是: " << result << endl; // 预期输出 3

    return 0;
}