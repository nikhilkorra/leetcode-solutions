#define ll long int
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
    bool validAux(TreeNode* root, ll min, ll max){
        if(root == NULL) return true;
        if(root->val <= min || root->val >= max) return false;
        return validAux(root->left, min, (ll)root->val) && 
                validAux(root->right, (ll)root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return validAux(root, (ll)INT_MIN - 1, (ll)INT_MAX + 1);
    }
};