//
// Created by A on 2026/3/15.
//
//正如Gemini所说，如果仅仅顺序遍历，random指向的节点可能会还未遍历到
//这样就成了黑箱探路，肯定无法实现
//于是采用unordered_map来存储
#include <unordered_map>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*,Node*> mp;//key:节点的原始地址 val:新节点的新地址
        Node* currNode=head;
        while (currNode!=nullptr)//遍历,将值先填入
        {
            mp[currNode]=new Node(currNode->val);
            currNode=currNode->next;
        }
        currNode=head;
        while (currNode!=nullptr)
        {
            mp[currNode]->next=mp[currNode->next];
            mp[currNode]->random=mp[currNode->random];
            currNode=currNode->next;
        }
        return mp[head];
    }
};