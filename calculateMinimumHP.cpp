//
// Created by A on 2026/3/26.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//逆向思维
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows=dungeon.size(),cols=dungeon[0].size();
        vector<vector<int>> dp(rows+1,vector<int>(cols+1,INT_MAX));
        //从公主的房间开始初始化,dp中值的定义为进入这个房间前最少的血量,才能进入公主的房间
        dp[rows][cols-1]=1;
        dp[rows-1][cols]=1;
        for (int i=rows-1;i>=0;i--)
        {
            for (int j=cols-1;j>=0;j--)
            {
                dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
//正向DP
const int inf=0x3f3f3f3f;
/*class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //二分
        int left=1,right=inf;
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if (judge(dungeon,mid)) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
    bool judge(vector<vector<int>>& dungeon,int hp)
    {
        int rows=dungeon.size(),cols=dungeon[0].size();
        vector<vector<int>> dp(rows+1,vector<int>(cols+1,-inf));
        //base case
        dp[1][1]=dungeon[0][0]+hp;
        for (int i=1;i<rows+1;i++)
        {
            for (int j=1;j<cols+1;j++)
            {
                //必须大于0才能往下走
                if (dp[i-1][j]>0) dp[i][j]=max(dp[i-1][j]+dungeon[i-1][j-1],dp[i][j]);
                if (dp[i][j-1]>0) dp[i][j]=max(dp[i][j-1]+dungeon[i-1][j-1],dp[i][j]);
            }
        }
        return dp[rows][cols]>0;
    }
};*/

int main() {
    Solution sol;
    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 3, -5}
    };

    int result = sol.calculateMinimumHP(dungeon);
    cout << "骑士需要的最小初始血量是: " << result << endl; // 预期输出 7

    return 0;
}
/*const int inf=0x3f3f3f3f3f;
class Solution {
public:
    bool judge(vector<vector<int>>dungeon,int hp){
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=-inf;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1&&j==1){
                    dp[i][j]=hp+dungeon[i-1][i-1];
                    continue;
                }
                if(dp[i-1][j]>0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+dungeon[i-1][j-1]);
                }
                if(dp[i][j-1]>0){
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+dungeon[i-1][j-1]);
                }
            }
        }
        if(dp[n][m]>0)return true;
        else return false;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int left=0,right=inf;
        while(left+1<right){
            int mid=(left+right)/2;
            if(judge(dungeon,mid)){
                right=mid;
            }else{
                left=mid;
            }
        }
        return right;
    }
};*/