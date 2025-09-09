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
    int res = 0;
    void traverseBST(TreeNode* node, int &k){
        if(node == NULL) return;
        traverseBST(node->left, k);
        k--;
        if(k == 0){
            res = node->val;    
            return;
        }
        traverseBST(node->right,k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        traverseBST(root, k);
        return res;
    }
};