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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *nil1, *nil2;
        nil1 = new ListNode(-1000);
        nil2 = new ListNode(-1000);
        ListNode *curr, *l, *r;
        curr=head;
        l=nil1;
        r=nil2;
        while(curr!=NULL){
            if(curr->val<x){
                l->next=curr;
                l=l->next;
            }
            else{
                r->next=curr;
                r=r->next;
            }
            curr=curr->next;
        }
        r->next=NULL;   // for heap used after free error
        l->next=nil2->next;
        return nil1->next;
    }
};