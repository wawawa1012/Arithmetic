//
// Created by A on 2026/3/13.
//
//index从0到数组最后一个元素，每次都可以选择拿或者不拿
//当index到nums.size()-1时，先把当前收集到的数组存入大的数组中，再return
//因此我们需要传入vector<vector<int>>& res，初始为空,用来存所有子数组，&确保不同递归对象可以共享同一个结果数组
//还要传入path，记录每个结果。所有递归对象也共享一个，因此也传引用
#include <iostream>
#include <vector>
using namespace std;
//递归解法
/*class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(nums,0,path,res);
        return res;

    }
private:
    void dfs(vector<int>& nums,int index,vector<int>& path,vector<vector<int>>& res)
    {
        if (index == nums.size()) {
            res.push_back(path); // vector 底层会帮你把当前的背包内容复印一份扔进铁桶
            return;              // 必须 return，毁灭当前克隆人！
        }
        if (index<nums.size())
        {
            path.push_back(nums[index]); //拿了这个数
            dfs(nums,index+1,path,res);//派克隆人探路，自己静止(不过是pushback(nums[index])之后，需要恢复本体才能往下正常运行）
            path.pop_back();//恢复
            dfs(nums,index+1,path,res);//忽略那个数
        }
   }
};*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        int digits=1<<n;//子集总数
        for (int i=0;i<digits;i++)
        {
            vector<int> temp;
            for (int j=0;j<n;j++)
            {
                if (i&(1<<j)) temp.push_back(nums[j]);//电脑里i是二进制表示，因此可以
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = sol.subsets(nums);

    cout << "二进制暴力破解的子集如下：" << endl;
    for (const auto& subset : res) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]" << endl;
    }
    return 0;
}