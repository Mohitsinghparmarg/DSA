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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       
        map<int, map<int, multiset<int>>> mpp;

       
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            TreeNode* temp = p.first;
            int x = p.second.first;
            int y = p.second.second;

          
            mpp[x][y].insert(temp->val);

         
            if (temp->left) {
                q.push({temp->left, {x - 1, y + 1}});
            }
            if (temp->right) {
                q.push({temp->right, {x + 1, y + 1}});
            }
        }

     
        vector<vector<int>> ans;
        for (auto p : mpp) {
            vector<int> res;
            for (auto r : p.second) {
                res.insert(res.end(), r.second.begin(), r.second.end());
            }
            ans.push_back(res);
        }

        return ans;
    }
};
