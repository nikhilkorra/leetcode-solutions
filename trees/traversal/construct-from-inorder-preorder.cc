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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl>pr || il>ir) return NULL;
        int r = preorder[pl];
        TreeNode* root = new TreeNode(r);
        // if(pl==pr) return root;
        int size=0, i=il;
        for(; i<=ir; i++){
            if(inorder[i]==r){
                size=i-il;
                break;
            }
        }
        root->left=build(preorder, inorder, pl+1, pl+size, il, i-1);
        root->right=build(preorder, inorder, pl+size+1, pr, i+1, ir);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};