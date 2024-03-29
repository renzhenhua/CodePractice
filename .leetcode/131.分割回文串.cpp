/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
   private:
    vector<vector<string>> res;
    vector<string> path;

    bool isPlainrome(const string& s, int l, int r) {
        for (int i = l, j = r; i <= j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

    void backtrack(const string& s, int start) {
        if (start == s.size()) {
            res.emplace_back(path);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPlainrome(s, start, i))
                // 获取[start, i]在s中的子串
                path.emplace_back(s.substr(start, i - start + 1));
            else
                continue;
            backtrack(s, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};

class Solution {
    vector<vector<string>> res;
    vector<string> path;
    void backtrack(const string& s, int idx) {
        if (idx == s.size()) {
            res.emplace_back(path);
            return;
        }

        for (int i = idx; i < s.size(); ++i) {
            if (isPalind(s, idx, i)) {
                // [idx, i] 闭区间
                path.emplace_back(s.substr(idx, i - idx + 1));
                backtrack(s, i + 1);
                path.pop_back();
            } else
                continue;
        }
    }
    bool isPalind(const string& s, int l, int r) {
        for (int i = l, j = r; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

   public:
    vector<vector<string>> partition(string s) {
        res.clear(), path.clear();
        backtrack(s, 0);
        return res;
    }
};
// @lc code=end
