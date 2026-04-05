//
// Created by A on 2026/4/5.
//
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 这是一个辅助工具箱：大老板怕你手撕剥离数字太累，允许你单独写个小函数
    // 专门用来计算一个数字的“各位平方和”
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }
  //哈希表存储
   /* bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
    while (n!=1)
    {
        int next=getNext(n);
        if (s.count(next)) return false;
        n=next;
        s.insert(n);
    }
    return true;
    }*/
    //快慢指针
    bool isHappy(int n)
    {
        int slow=n,fast=n;
        while (slow!=1&&fast!=1)
        {
            slow=getNext(slow);
            fast=getNext(getNext(fast));
            if (fast==slow&&slow!=1) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    cout << "测试 1 (19): " << (sol.isHappy(10) ? "是快乐数" : "不是快乐数") << endl; // 预期: 是快乐数
    cout << "测试 2 (2): " << (sol.isHappy(2) ? "是快乐数" : "不是快乐数") << endl; // 预期: 不是快乐数

    return 0;
}