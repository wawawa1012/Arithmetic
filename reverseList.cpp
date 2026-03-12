//
// Created by A on 2026/3/12.
//
 //Definition for singly-linked list.
  struct ListNode {
          int val;
          ListNode *next;
          ListNode() : val(0), next(nullptr) {}
          ListNode(int x) : val(x), next(nullptr) {}
          ListNode(int x, ListNode *next) : val(x), next(next) {}
      };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;//前驱节点，初始为空
        ListNode* curr=head; //当前节点，要被遍历，初始为头结点
        while (curr!=nullptr)
        {
            ListNode* temp=curr->next;//存档，防止内存泄漏
            curr->next=prev;//反转
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};