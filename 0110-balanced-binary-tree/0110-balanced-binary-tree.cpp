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

   int Solve(TreeNode* &root){
             
             if(root == NULL)
                return 0;
            int leftPart = Solve(root->left);
            if(leftPart == -1)
                  return -1;
            int rightPart = Solve(root->right);
            if(rightPart == -1)
                  return -1;
            if(abs(leftPart - rightPart) > 1)
                   return -1;
         return max(leftPart,rightPart) + 1;
   }


    bool isBalanced(TreeNode* root) {
             
             return Solve(root) != -1;
    }
};