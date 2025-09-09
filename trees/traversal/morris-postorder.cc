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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> res;
        while(curr!=NULL){
            if(curr->right==NULL){
                res.push_back(curr->val);
                curr=curr->left;
            }
            else{
                TreeNode* callback_node = curr->right;
                while(callback_node->left!=NULL && callback_node->left!=curr) 
                    callback_node=callback_node->left;
                if(callback_node->left==NULL){
                    callback_node->left=curr;
                    res.push_back(curr->val);
                    curr=curr->right;
                }
                else{
                    curr=callback_node->left;
                    callback_node->left=NULL;
                    curr=curr->left;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};