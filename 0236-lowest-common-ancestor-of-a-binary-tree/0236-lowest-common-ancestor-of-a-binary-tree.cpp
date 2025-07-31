/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         
         if(root == NULL || root == p || root == q){
                return root;
         }
         TreeNode* leftPortion = lowestCommonAncestor(root->left,p,q);
         TreeNode* rightPortion = lowestCommonAncestor(root->right,p,q);
        if(leftPortion == NULL){
              return rightPortion;
        }
        if(rightPortion == NULL){
            return leftPortion;
        }
        else{
            return root;
        }
    }
};