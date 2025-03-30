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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
           
           vector<vector<int>>ans;
          if(root == NULL)
                return ans;
          queue<TreeNode*>q;
          q.push(root);
          bool leftToRight = true;
         while(!q.empty()){
               int size = q.size();
               vector<int>v(size);
             for(int i = 0; i<size; i++){
                  TreeNode* node = q.front();
                  q.pop();
                int j = leftToRight ? i : size - i -1;
                 if(node->left) q.push(node->left);
                 if(node->right) q.push(node->right);
                 v[j] = node->val;
             }
             leftToRight = !leftToRight;
             ans.push_back(v);
         }
         return ans;
    }
};