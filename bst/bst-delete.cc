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
    void transplant(TreeNode *p, TreeNode *u, TreeNode *v){
        if(p->left == u) p->left = v;
        else p->right = v;
        return;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *nil = new TreeNode(0);
        nil->left = root;
        TreeNode *x = root, *p = nil;
        while(x && x->val != key){
            p = x;
            if(x->val > key) x = x->left;
            else x = x->right;
        }
        if(!x) return root;
        // cout<<x->val<<' '<<p->val<<endl;
        if(x->left == NULL){
            transplant(p, x, x->right);
        }
        else if(x->right == NULL){
            transplant(p, x, x->left);
        }
        else{
            // TreeNode *y, *yp = successor(x);
            TreeNode *y = x->right, *yp = x;
            while(y &&  y->left){
                yp = y;
                y = y->left;
            }
            // cout<<y->val<<' '<<yp->val<<endl;
            if(y == x->right){
                y->left = x->left;
                transplant(p, x, y);
            }
            else{
                transplant(yp, y, y->right);
                x->val = y->val;
            }
        }
        return nil->left;
    }
};