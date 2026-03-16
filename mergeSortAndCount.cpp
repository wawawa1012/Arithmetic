//
// Created by A on 2026/3/16.
//
//brute force解法就是直接对每个元素遍历，再对每个其他元素遍历，上界O(n^2)
//如果用分而治之的思想，那么需要分别找左半边和右半边的逆序对tn=2tn/2+额外
//其次可能左边的元素大于右边的，所以在每次递归还要找到左边大于右边的解的个数
//如果用for循环，那额外=O(n^2),则最终也是算法上界
//Gemini提示conquer的同时merge成有序的数组交给上层（我不知道是怎么自然想到的），这样就只要O(n)的额外开销，d=1
//总复杂度是O(nlogn)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // 如果数组太小，直接没有逆序对
        if (nums.size() < 2) return 0;

        // 你可能需要一个全局或传递的辅助数组 temp，用来做归并排序的合并
        vector<int> temp(nums.size());

        return mergeSortAndCount(nums, 0, nums.size() - 1, temp);
    }

private:
    int mergeSortAndCount(vector<int>& nums, int left, int right, vector<int>& temp) {
        // 战场交给你了！写出你的分治与跨界捕获逻辑！
        // 1. Base case
        if (left>=right) return 0;
        // 2. 切分 (Divide)
        int mid=left+(right-left)/2;
        // 3. 递归找左右半场的逆序对 (Conquer)
        int leftPair=mergeSortAndCount(nums,left,mid,temp);
        int rightPair=mergeSortAndCount(nums,mid+1,right,temp);
        // 4. 合并有序数组，并顺手计算跨界逆序对 (Combine)
        int i = left;      // 老板的左手指针，指向左半场开头
        int j = mid + 1;   // 老板的右手指针，指向右半场开头
        int k = left;      // 草稿纸 temp 的写字指针
        int combinePair = 0; // 记录跨界的逆序对
        while (i <= mid && j <= right)
        {
            if (nums[i]<=nums[j])//顺序
            {
                temp[k]=nums[i];
                i++;k++;
            }
            else//逆序需要计算越过分界线的pair
            {
                combinePair+=(mid-i+1);//左边的从下标为i到下标为mid均大于nums[j]
                temp[k]=nums[j];
                j++;k++;
            }
        }
        // 打扫战场：如果左半场还有剩下的，全抄上去
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        // 打扫战场：如果右半场还有剩下的，全抄上去
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        for (int p = left; p <= right; p++) {
            nums[p] = temp[p];
        }
        return leftPair + rightPair + combinePair;
    }
};