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
    vector<TreeNode*> generateTreesAux(int i, int j){
        vector<TreeNode*> res;
        if(i>j){
            res.push_back(nullptr);
            return res;
        }
        if(i==j){
            TreeNode *root = new TreeNode(i);
            res.push_back(root);
            return res;
        }
        for(int r=i; r<=j; r++){
            vector<TreeNode*> leftTree  = generateTreesAux(i, r-1);
            vector<TreeNode*> rightTree = generateTreesAux(r+1, j);
            for(auto left:leftTree){
                for(auto right:rightTree){
                    TreeNode *root = new TreeNode(r);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateTreesAux(1, n);
    }
};