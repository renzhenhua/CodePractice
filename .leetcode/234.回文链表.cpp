/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        ListNode* p = head;
        while (p) {
            res.emplace_back(p->val);
            p = p->next;
        }

        p = head;
        for (int i = res.size() - 1; i >= 0; --i) {
            if (res[i] == p->val) {
                p = p->next;
            } else {
                return false;
            }
        }
        return true;
    }
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;

        ListNode* cur1 = head;
        ListNode* cur2 = reverseList(slow);

        while (cur1) {
            if (cur1->val != cur2->val) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }
};

class Solution {
   public:
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* tail = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        int i = 0;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            i++;
        }
        ListNode* tail = reverse(slow);
        slow->next = nullptr;
        while (i--) {
            if (head->val == tail->val)
                head = head->next, tail = tail->next;
            else
                return false;
        }
        return true;
    }
};

class Solution {
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* tail = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }

   public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* cur = reverse(slow);
        while (cur && head) {
            if (cur->val != head->val)
                return false;
            else
                cur = cur->next, head = head->next;
        }
        return true;
    }
};
// @lc code=end
