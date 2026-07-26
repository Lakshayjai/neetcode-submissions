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
    void f(TreeNode* root, int maxVal, int& ansCnt, int& cnt){
        if(root == NULL) return;
        if(root -> val >= maxVal){
            ansCnt++;
            maxVal = root -> val;
            if(root -> val == maxVal){
                cnt++;
            }else{
                cnt = 1;
            }
        }

        f(root -> left, maxVal, ansCnt, cnt);
        f(root -> right, maxVal, ansCnt, cnt);
    }

    int goodNodes(TreeNode* root) {
        int ansCnt = 0;
        int cnt = 1;
        int maxVal = -1e9;

        f(root, maxVal, ansCnt, cnt);
        return ansCnt;
    }
};
