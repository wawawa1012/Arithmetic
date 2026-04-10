#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue> // 调包！机试能调包就调包！

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 绝对静音模式！
        
        // 1. 开个哈希表当账本，统计频率
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // 2. 召唤 VIP 俱乐部：小顶堆！
        // 里面存的是 pair<频率, 数字>，比较器用 greater 实现小顶堆
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        
        // 3. 遍历哈希表，让元素带着它的频率去俱乐部踢馆！
        for (auto& pair:freqMap)
        {
            if (minHeap.size()<k) minHeap.push({pair.second,pair.first});
            else
            {
                if (minHeap.top().first<=pair.second)
                {
                    minHeap.pop();
                    minHeap.push({pair.second,pair.first});
                }
            }
        }
        
        
        // 4. 选秀结束，把俱乐部里剩下的数字取出来，扔进答案 vector 里
        vector<int> res;
        while (!minHeap.empty())
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    vector<int> r1 = sol.topKFrequent(nums1, 2);
    cout << "测试 1 (预期 1 2 或 2 1): ";
    for (int x : r1) cout << x << " "; cout << endl;

    return 0;
}