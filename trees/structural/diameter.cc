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
    int height(TreeNode* node, int &maxh){
        if(node==NULL) return 0;
        int hl = height(node->left, maxh);
        int hr = height(node->right, maxh);
        maxh = max(maxh, hl+hr);
        return max(hl, hr)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxh=0;
        height(root, maxh);
        return maxh;
    }
};