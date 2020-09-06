/*
146. LRU缓存机制
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用)
缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果关键字 (key)
存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。 写入数据 put(key,
value) -
如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。
当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。



进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？



示例:

LRUCache cache = new LRUCache( 2 缓存容量  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得关键字 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得关键字 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
   private:
    struct Node {
        int key;
        int val;
        Node* pre;
        Node* next;
        Node() : key(-1), val(-1), pre(nullptr), next(nullptr) {}
        Node(int x, int y) : key(x), val(y), pre(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> map;
    int cnt = 0;
    int size;

   public:
    LRUCache(int capacity) {
        head = new Node();
        tail = head;
        size = capacity;
    }

    int get(int key) {
        auto iter = map.find(key);
        if (iter == map.end()) {
            return -1;
        }
        Node* p = iter->second;
        if (p != tail) {
            remove(p);
            append(p);
        }
        return p->val;
    }

    void put(int key, int value) {
        auto iter = map.find(key);
        if (iter == map.end()) {
            if (cnt == size) {    
                Node* p = head->next;   
                remove(p);
                map.erase(p->key);
                delete p;
                cnt--;
            }
            Node* p = new Node(key, value);
            append(p);

            map[key] = p;
            cnt++;
        } else {
            Node* p = iter->second;
            p->val = value;
            if (p != tail) {
                remove(p);
                append(p);
            }
        }
    }

    void remove(Node* p) {
        p->pre->next = p->next;
        if(p->next){
            p->next->pre = p->pre;
        }
        if(head->next == nullptr){
            tail = head;
        }
    }

    void append(Node* p) {
        tail->next = p;
        p->pre = tail;
        tail = p;
        tail->next = nullptr;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache* cache = new LRUCache(2);

    // cache->put(1, 1);
    // cache->put(2, 2);
    // cout << cache->get(1) << endl;  // 返回  1
    // cache->put(3, 3);               // 该操作会使得关键字 2 作废
    // cout << cache->get(2) << endl;  // 返回 -1 (未找到)
    // cache->put(4, 4);               // 该操作会使得关键字 1 作废
    // cout << cache->get(1) << endl;  // 返回 -1 (未找到)
    // cout << cache->get(3) << endl;  // 返回  3
    // cout << cache->get(4) << endl;  // 返回  4

    cache->put(2, 1);
    cache->put(1, 1);
    cache->put(2, 3);
    cache->put(4, 1);
    cout << cache->get(1) << endl;  // 返回  1
    cout << cache->get(2) << endl;

    return 0;
}