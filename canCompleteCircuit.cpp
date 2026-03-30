//
// Created by A on 2026/3/30.
//
#include <iostream>
#include <vector>
//最暴力应该就是强行从每个节点开始，计算gas[i]-cost[i],可以就返回那个解，不可以就continue
//下标用mod可以算，也可以通过起点的gas和cost相减判断小于零直接剪枝,或者gas和小于cost和直接失败
//写了一下，发现是O(n^2)的复杂度，直觉告诉我可能可以优化到O(n)
//这个题问了找到可行解，Gemini昨天告诉我用贪心或DP
using namespace std;

//暴力
/*class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int g_sum = 0, c_sum = 0;
        int size = gas.size();
        for (int g : gas) g_sum += g;
        for (int c : cost) c_sum += c;
        if (g_sum < c_sum) return -1;
        for (int startID = 0; startID < size; startID++)
        {
            //剪枝
            if (gas[startID] < cost[startID]) continue;
            int currGas=0; //记录当前剩余油量
            for (int i=startID;i<startID+size;i++)
            {
                int index=i%size;
                currGas+=gas[index]-cost[index];
                if (currGas < 0) break;
            }
            if (currGas<0) continue;
            else return startID;
        }
        return -1;
    }
};*/

//贪心(如果i站发现当前油量小于0，则直接跳到i+1)
class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int total_surplus=0;//利用总盈亏剪枝
        int size = gas.size();
        int start_station=0,currGas=0;
        for (int i=0;i<size;i++)
        {
            int net_gas = gas[i] - cost[i]; // 这一站的净盈亏

            total_surplus += net_gas; // 顺手记入全局总账本
            currGas += net_gas;       // 加进当前赛车的油箱
            if (currGas<0)
            {
                start_station=i+1;
                currGas=0;
            }
        }
        if (total_surplus < 0) return -1;
        return start_station;
    }
};
int main()
{
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << "最佳起跑线是: " << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
