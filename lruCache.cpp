//
// Created by A on 2026/4/19.
//
#include <iostream>
#include <unordered_map>

using namespace std;

// 1. 极其底层的双向链表节点定义
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

    // 刑具 1：加到头部 (塞到 head 墙和第一个真实节点之间)
    void addToHead(DLinkedNode* node) {
        node->prev = head;          // 我的左手拉住 head 墙
        node->next = head->next;    // 我的右手拉住原本的第一个节点
        head->next->prev = node;    // 原本的第一个节点的左手拉住我
        head->next = node;          // head 墙的右手拉住我
    }

    // 刑具 2：从原位置抠出来 (绝对不要 delete！)
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next; // 我左边兄弟的右手，越过我，拉住我右边的兄弟
        node->next->prev = node->prev; // 我右边兄弟的左手，越过我，拉住我左边的兄弟
        // 此时 node 已经极其完美地脱离了队伍
    }

    // 刑具 3：提拔！
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    // 刑具 4：处决队尾 (把 tail 墙前面的那个倒霉蛋抠出来)
    DLinkedNode* removeTail() {
        DLinkedNode* res = tail->prev;
        removeNode(res);
        return res; // 返回它是为了去 Hash 表里注销户口！
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1; // 查无此人
        }
        // 如果找到了，极其冷酷地把它提拔到 VIP 头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value; // 返回的是真实数据，不是 key！
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            // 如果本来就有：覆盖旧数据，提拔！
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            // 如果是新来的：上户口，放进头部
            DLinkedNode* newNode = new DLinkedNode(key, value);
            cache[key] = newNode;
            addToHead(newNode);
            size++;

            // 极其致命的容量警告！
            if (size > capacity) {
                // 1. 从链表里抠出最久没用的队尾
                DLinkedNode* tailNode = removeTail();
                // 2. 去 Hash 表里极其无情地注销它的户口 (这就是为什么 Node 里要存 key!)
                cache.erase(tailNode->key);
                // 3. 彻底释放物理内存，销毁尸体！
                delete tailNode;
                size--;
            }
        }
    }
};