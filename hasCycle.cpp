//
// Created by A on 2026/3/14.
//
//如果暴力破解 ，可以用数组或容器记录某个节点是否走过，只要currNode不是nullptr,往前走即可，不过要开辟额外的空间
//这道题可以用套圈的思想完成,可以不开额外空间，是原地算法

#include <unordered_set>
using namespace std;
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode* fast=head; //每次走两步
        ListNode* slow=head;//每次走一步
        while (fast!=nullptr&&fast->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
            if (fast==slow) return true;
        }
        return false;
    }
};
/*class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* currNode=head;
        unordered_set<ListNode*> is_visited;
        while (currNode!=nullptr)
        {
            if (is_visited.count(currNode)) return true;
            is_visited.insert(currNode);
            currNode=currNode->next;
        }
        return false;
    }
};*/