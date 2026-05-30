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
    vector<int> rightSideView(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        vector<int> v;
        if(!root){
            return v;
        }
        s.push({root,1});
        
        int maxDepth = 0;

        int size = 1;
        while(!s.empty()){
            int count = 0;

            for(int i = 0; i< size; i++){

                if(maxDepth < s.top().second){
                    v.push_back(s.top().first->val);
                    maxDepth = s.top().second;
                }
                pair<TreeNode*, int> f = s.top();
                s.pop();
                if(f.first->left){
                    s.push({f.first->left,f.second+1});
                    count++;
                }
                if(f.first->right){
                    s.push({f.first->right,f.second+1});
                    count++;
                }
                
            }
            size = count;

        }
        return v;

    }
};
