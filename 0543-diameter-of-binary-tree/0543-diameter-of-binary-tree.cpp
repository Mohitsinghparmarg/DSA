/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

  int solve(TreeNode*root,int& diameter){
         
           if(root == NULL){
               return 0;
           }
         int leftHeight = solve(root->left,diameter);
         int rightHeight = solve(root->right,diameter);
         diameter = max(diameter,leftHeight + rightHeight);
         return 1 + max(leftHeight , rightHeight);
  }
    int diameterOfBinaryTree(TreeNode* root) {
            int diameter = 0;
            solve(root,diameter);
           return diameter;
    }
};