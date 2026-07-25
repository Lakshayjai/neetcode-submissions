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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;
        if(p and q and p->val == q->val){
            return isSameTree(p->left, q->left) and 
            isSameTree(p->right, q->right);
        }
        
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (root == NULL)
            return false;
        
        if(isSameTree(root, subRoot)){
            return true;
        }

        return isSubtree(root -> left, subRoot) or isSubtree(root -> right, subRoot);
    }
};
