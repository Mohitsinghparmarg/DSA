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
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            int minimum_index = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++) {
                long long current_index = q.front().second - minimum_index;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) {
                    first = current_index;
                }
                if (i == size - 1) {
                    last = current_index;
                }
                if (node->left) {
                    q.push({node->left, current_index * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, current_index * 2 + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};