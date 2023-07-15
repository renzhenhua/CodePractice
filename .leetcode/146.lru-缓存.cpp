/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
// 靠近首部的键值对是最近使用的，尾部的是之后要淘汰的
class LRUCache {
    int capacity_;
    list<int> keyList_;
    unordered_map<int, pair<int, list<int>::iterator>> hashMap_;
    void insert(int key, int value) {
        keyList_.emplace_front(key);
        hashMap_[key] = make_pair(value, keyList_.begin());
    }

   public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        auto it = hashMap_.find(key);
        if (it != hashMap_.end()) {
            keyList_.erase(it->second.second);
            keyList_.emplace_front(key);
            hashMap_[key].second = keyList_.begin();
            return it->second.first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            // 注意get操作导致已经移动到头部了
            hashMap_[key].first = value;
            return;
        }
        if (hashMap_.size() < capacity_) {
            insert(key, value);
        } else {
            int removeKey = keyList_.back();
            keyList_.pop_back();
            hashMap_.erase(removeKey);

            insert(key, value);
        }
    }
};

class LRUCache {
    int capacity_;
    list<int> keyList_;
    unordered_map<int, pair<int, list<int>::iterator>> hashMap_;
    void insert(int key, int value) {
        keyList_.emplace_front(key);
        hashMap_[key] = make_pair(value, keyList_.begin());
    }

   public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        auto it = hashMap_.find(key);
        if (it != hashMap_.end()) {
            keyList_.erase(it->second.second);
            insert(key, it->second.first);
            return it->second.first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            hashMap_[key].first = value;
            return;
        }

        if (hashMap_.size() < capacity_) {
            insert(key, value);
            return;
        } else {
            int removeKey = keyList_.back();
            keyList_.pop_back();
            hashMap_.erase(removeKey);

            insert(key, value);
        }
    }
};

// 使用自己定义的双向链表
class LRUCache {
   private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
        Node(int _key, int _value)
            : key(_key), value(_value), prev(nullptr), next(nullptr) {}
    } *head, *tail;
    unordered_map<int, Node*> hashMap_;
    int capacity_;

    void insert(int key, int value) {
        Node* node = new Node(key, value);
        hashMap_[key] = node;
        // 添加至双向链表的头部
        addToHead(node);
    }

   public:
    LRUCache(int capacity) : capacity_(capacity) {
        // 使用伪头部和伪尾部节点
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        auto it = hashMap_.find(key);
        if (it != hashMap_.end()) {
            // 如果 key 存在，先通过哈希表定位，再移到头部
            Node* node = hashMap_[key];
            removeNode(node);
            addToHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            // 注意get操作导致已经移动到头部了
            Node* node = hashMap_[key];
            node->value = value;
            return;
        }
        if (hashMap_.size() < capacity_) {
            insert(key, value);
        } else {
            // 如果超出容量，删除双向链表的尾部节点
            Node* removed = removeTail();
            // 删除哈希表中对应的项
            hashMap_.erase(removed->key);
            // 防止内存泄漏
            delete removed;

            insert(key, value);
        }
    }

    void addToHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
