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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> res;
        while(curr!=NULL){
            if(curr->left==NULL){
                res.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* callback_node = curr->left;
                while(callback_node->right!=NULL && callback_node->right!=curr) 
                    callback_node=callback_node->right;
                if(callback_node->right==NULL){
                    callback_node->right=curr;
                    curr=curr->left;
                }
                else{
                    curr=callback_node->right;
                    callback_node->right=NULL;
                    res.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return res;
    }
};