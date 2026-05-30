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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int size = 1;
        if (!root){
            return {};
        } 
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0){
            int counter =0;
            //need to collect children for {size} ones. Add them to the next row, reinitialize size for the number of kids which is count
            v.push_back({});
            for(int i = 0; i< size; i++){
                if(q.front()){
                    v.back().push_back(q.front()->val);
                    if(q.front()->left){
                        q.push(q.front()->left);
                        counter++;
                    }
                    if(q.front()->right){
                        q.push(q.front()->right);
                        counter++;
                    }
                    q.pop();
                }
            }
            size = counter;
        }
        return v;
    }
};
