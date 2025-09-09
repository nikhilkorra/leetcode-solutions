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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *z = new TreeNode(val);
        TreeNode *x = root, *y = NULL;
        while(x != NULL){
            y = x;
            if(x->val > val) x = x->left;
            else x = x->right;
        }
        if(y == NULL) return z;
        if(y->val > val) y->left = z;
        else y->right = z;
        return root;
    }
};