//
// Created by A on 2026/3/10.
//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//返回容器可以储存的最大水量。
//思路：双指针

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0; // 改名，避免和函数名冲突

        // 只要两个小人还没相遇，就算到底
        while (left < right) {
            // 1. 先计算当前两个小人构成的面积
            int current_area = min(height[left], height[right]) * (right - left);

            // 2. 更新历史最大纪录
            max_area = max(max_area, current_area);

            // 3. 核心物理逻辑：谁短谁就往中间走，寻找翻盘的机会
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};

int main()
{
    Solution s;
    vector<int> height={1,8,6,2,5,4,8,3,7};
   cout<<s.maxArea(height);
}
