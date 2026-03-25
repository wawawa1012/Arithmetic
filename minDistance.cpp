#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1=word1.size(),w2=word2.size();
        //dp的值定义是把 word1 的前 i 个字符，改造成 word2 的前 j 个字符，最少需要动几次手术
        vector<vector<int>> dp(w1+1,vector<int>(w2+1,0));
        for (int i=1;i<=w1;i++) dp[i][0]=i;
        for (int j=1;j<=w2;j++) dp[0][j]=j;
        for (int i=1;i<=w1;i++)
        {
            for (int j=1;j<=w2;j++)
            {
                if (word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min({dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1});//不同则采用替换、删除、插入三种方法中的最小值
            }
        }
        return dp[w1][w2];
    }
};

int main() {
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";

    int result = sol.minDistance(word1, word2);
    cout << "改造成目标单词所需的最少手术次数: " << result << " 次" << endl; // 预期输出 3

    return 0;
}