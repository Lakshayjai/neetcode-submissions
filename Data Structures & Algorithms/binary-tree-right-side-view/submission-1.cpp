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
        if(root == NULL) return {};

        TreeNode* temp = root;
        vector<int> ans;

        queue<TreeNode*> q;
        q.push(temp);

        while(!q.empty()){
            int size = q.size();
            while(size){
                TreeNode* node = q.front();
                q.pop();
                if(size == 1){
                    ans.push_back(node -> val); 
                }

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
                size--;
            }
        }
        return ans;
    }
};
