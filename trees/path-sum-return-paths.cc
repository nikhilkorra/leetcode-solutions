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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(!root) return res;
        stack<tuple<TreeNode*, int, vector<int>>> st;
        st.push({root, root->val, {root->val}});
        while(!st.empty()){
            auto [node, sum, path] = st.top();
            st.pop();
            if(node->right){
                auto curr_path = path;
                curr_path.push_back(node->right->val);
                st.push({node->right, sum + node->right->val, curr_path});
            }
            else{
                if(!node->left && sum == targetSum){
                    res.push_back(path);
                }
            }
            if(node->left){
                auto curr_path = path;
                curr_path.push_back(node->left->val);
                st.push({node->left, sum + node->left->val, curr_path});
            }
        }
        return res;

    }
};