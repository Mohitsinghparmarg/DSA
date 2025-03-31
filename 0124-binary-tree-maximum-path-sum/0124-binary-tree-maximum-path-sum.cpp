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
class Solution {
public:
    int Solve(TreeNode* root, int& MaxSum) {
        if (root == NULL)
            return 0;
        int LeftSum = max(0, Solve(root->left, MaxSum));
        int RightSum = max(0, Solve(root->right, MaxSum));
        MaxSum = max(MaxSum, LeftSum + RightSum + root->val);
        return max(LeftSum, RightSum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int MaxSum = INT_MIN;
        Solve(root, MaxSum);
        return MaxSum;
    }
};