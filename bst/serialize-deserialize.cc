#include<string>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeAux(root, out);
        cout<<out.str()<<endl;
        return out.str();
    }
    void serializeAux(TreeNode *root, ostringstream &out){
        if(root == NULL) return;
        out << root->val << ',' ;
        serializeAux(root->left, out);
        serializeAux(root->right, out);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int l = 0;
        return deserializeAux(data, l, INT_MIN, INT_MAX);
    }
    TreeNode* deserializeAux(string &data, int &l, int min, int max){
        if(l >= data.length()) return NULL;
        int start = l;
        while(data[l] != ',') l++;
        int val = stoi(data.substr(start, l - start));
        l++;
        if(val < min || val > max){
            l = start;
            return NULL;
        }
        TreeNode* node = new TreeNode(val);
        node->left = deserializeAux(data, l, min, val);
        node->right = deserializeAux(data, l, val, max);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;