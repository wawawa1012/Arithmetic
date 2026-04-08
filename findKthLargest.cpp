//
// Created by A on 2026/4/8.
//
#include <iostream>
#include <vector>
#include <queue> // 必须包含这个头文件

using namespace std;
//现成的小顶堆(掉包侠）
/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 绝对静音模式！
        //
        // 召唤小顶堆的古老咒语 (直接抄，不用背，机试时如果有代码补全就爽了，没有就稍微记一下)：
        // priority_queue<类型, 容器, 比较器>
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // 大老板的战术指导：
        // 1. 先无脑把数组的前 k 个元素塞进俱乐部 (minHeap.push())
        // 2. 对于剩下的元素 (从下标 k 开始到最后)：
        //    拿它和门卫 (minHeap.top()) 比武。
        //    赢了？把门卫踢走 (minHeap.pop())，自己进去 (minHeap.push())！
        //    输了？无视它。
        // 3. 循环结束，门卫 (minHeap.top()) 就是你要找的答案！
        for (int i=0;i<k;i++)
        {
            minHeap.push(nums[i]);
        }
        for (int i=k;i<nums.size();i++)
        {
            if (minHeap.top()<nums[i])
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};*/

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int n=nums.size();
        for (int i=n/2-1;i>=0;i--)//倒数第一个非叶子节点的绝对公式是：n / 2 - 1
        {
            sift_down(nums,i);
        }
        for (int j=1;j<=k-1;j++)
        {
            swap(nums[0],nums[n-j]);
            nums.pop_back();
            sift_down(nums,0);
        }
        return nums[0];
    }
private:
    void sift_down(vector<int>& nums,int i)
    {
        int n=nums.size();
        while (2*i+1<n) //有左孩子且尚未成堆
        {
            int curr=nums[i]; //当前要操作的值
            int j=2*i+1;//指向左孩子
            if (j+1<n&& nums[j + 1] > nums[j]) //有右孩子
            {
                j++;
            }
            if (curr>=nums[j]) //成堆了
            {
                break;
            }
            else//交换
            {
                swap(nums[i],nums[j]);
                i=j;//继续往下
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    cout << "测试 1 (预期 5): " << sol.findKthLargest(nums1, 2) << endl;

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << "测试 2 (预期 4): " << sol.findKthLargest(nums2, 4) << endl;

    return 0;
}