#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. 造一个太上皇，挡在真实老大 head 的前面
        ListNode* dummy = new ListNode(0, head);

        // 2. 乌龟和兔子一开始都在太上皇这里
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // 3. 让兔子先飞奔 n 步，拉开 n 个身位的差距
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // 4. 等等！我们要删的是目标节点，所以乌龟必须停在目标节点的【前一个】！
        // 因此，再让兔子往前走 1 步，总共拉开 n+1 个身位
        fast = fast->next;

        // 5. 两人保持距离，一起跑！直到兔子撞墙
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 6. 此时，slow 刚好停在被删节点的【正前方】！
        ListNode* target = slow->next;       // 锁定要被枪毙的那个节点
        slow->next = slow->next->next;       // 绕过它（解开链条）
        delete target;                       // 物理超度，防止内存泄露！

        // 7. 返回太上皇后面的真实排头
        ListNode* newHead = dummy->next;
        delete dummy;                        // 走之前别忘了把临时请来的太上皇也送走
        return newHead;
    }
};