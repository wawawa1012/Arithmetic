#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. 造太上皇 (Dummy Node)
        ListNode* dummy_head=new ListNode(0,head);
        // 2. 召唤乌龟和兔子，放在太上皇的位置
        ListNode* fast=dummy_head;
        ListNode* slow=dummy_head;
        // 3. 让兔子先跑，拉开间距 (注意要拉开 n+1 的间距！),slow需要在待删除节点的前驱节点才可删除
        for (int i=0;i<n;i++) fast=fast->next;
        fast=fast->next;
        // 4. 龟兔赛跑，直到兔子撞墙
        while (fast!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        // 5. 乌龟执行物理超度 (删除目标节点，别忘了 delete 防止内存泄露！)
        ListNode* delNode=slow->next;
        slow->next=delNode->next;
        delete delNode;
        // 6. 返回太上皇后面的真实排头，并把太上皇也送走
        ListNode* newHead=dummy_head->next;
        delete dummy_head;
        return newHead;
    }
};