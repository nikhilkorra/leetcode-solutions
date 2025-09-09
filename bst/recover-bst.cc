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
    TreeNode *one = NULL, *two = NULL, *prev = NULL;
    void assignNodes(TreeNode* root){
        if(root == NULL) return;
        assignNodes(root->left);
        if(prev && prev->val > root->val){
            if(!one) one = prev;
            two = root;
        }
        prev = root;
        assignNodes(root->right);
    }
    void recoverTree(TreeNode* root) {
        assignNodes(root);
        // one->val = one->val ^ two->val;
        // two->val = one->val ^ two->val;
        // one->val = one->val ^ two->val;
        swap(one->val, two->val);
        return;
    }
};