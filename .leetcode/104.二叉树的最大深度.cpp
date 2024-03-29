/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// 543, 124, 104 可以一起看
// 递归
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// 递归2
class Solution {
   public:
    int getdepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftdepth = getdepth(node->left);        // 左
        int rightdepth = getdepth(node->right);      // 右
        int depth = 1 + max(leftdepth, rightdepth);  // 中
        return depth;
    }
    int maxDepth(TreeNode* root) { return getdepth(root); }
};

// dfs
class Solution {
   public:
    int maxd = 0;
    void dfs(TreeNode* root, int d) {
        if (!root) return;
        maxd = max(maxd, d);
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return maxd;
    }
};

// 使用队列进行层序遍历
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        int maxd = 0;
        queue<TreeNode*> q;
        if (!root) return maxd;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            maxd++;
            while (len--) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return maxd;
    }
};

// 类似543
class Solution {
    int res = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        res = max(left + 1, max(right + 1, res));
        return max(left, right) + 1;
    }

   public:
    int maxDepth(TreeNode* root) {
        dfs(root);
        return res;
    }
};
// @lc code=end
