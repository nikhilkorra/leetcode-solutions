/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* node;
    TreeNode* generateBST(int l, int r){
        if(l > r) return NULL;
        int mid = (l + r) / 2;
        TreeNode *left = generateBST(l, mid - 1);
        TreeNode *tree = new TreeNode(node->val);
        tree->left = left;
        node = node->next;
        TreeNode *right = generateBST(mid + 1, r);
        tree->right = right;
        return tree;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        node = head;
        int n = 0;
        while(head != NULL){
            head = head->next;
            n++;
        }
        return generateBST(0, n - 1);

    }
};