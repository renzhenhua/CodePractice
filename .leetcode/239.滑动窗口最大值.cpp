/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (q.size() && i - k + 1 > q.front()) q.pop_front();
            while (q.size() && nums[i] > nums[q.back()]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};

// while里面条件 = 也可以
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (q.size() && i - q.front() + 1 > k) q.pop_front();
            while (q.size() && nums[i] >= nums[q.back()]) q.pop_back();
            q.emplace_back(i);
            if (i >= k - 1) res.emplace_back(nums[q.front()]);
        }
        return res;
    }
};
// @lc code=end
