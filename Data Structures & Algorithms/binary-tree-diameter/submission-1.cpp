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
    int maxDepth(TreeNode* root) {

        if(root == NULL) return 0;

        TreeNode* temp = root;
        int depth = 0;

        queue<TreeNode*> q;
        q.push(temp);

        while(!q.empty()){
            int size = q.size();
            depth++;
            while(size){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
                size--;
            }
        }

        return depth;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int R_cnt = maxDepth(root->left) + maxDepth(root->right);
        int cnt = max(diameterOfBinaryTree(root -> left), diameterOfBinaryTree(root -> right));
        return max(R_cnt, cnt);
    }
};
