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
    int goodNodes(TreeNode* root) {
        int pathMax = 0; 
        if(!root)
            return 0;
        stack<pair<TreeNode*, int>> s;

        s.push({root, root->val});
        int count= 0;
        while(!s.empty()){
            TreeNode* n = s.top().first;
            int curMax = s.top().second;
            if(curMax <= n->val){
                count++;
            }
            s.pop();
            if(n->left){
                
                s.push({ n->left, max(n->left->val, curMax) });
            }
            if(n->right){
                
                s.push({ n->right, max(n->right->val, curMax) });
            }
            

        }

        return count;


    }
};
