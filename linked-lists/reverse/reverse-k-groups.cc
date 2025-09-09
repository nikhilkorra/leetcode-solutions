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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr, *prev, *nil;
        nil=new ListNode(-1000);
        nil->next=head;
        curr=head;
        prev=nil;
        for(int i=0; i<left-1; i++){
            prev=curr;
            curr=curr->next;
        }
        ListNode *rprev, *tmp, *rtail;
        rprev=NULL;
        rtail=curr;
        for(int i=0; i<right-left; i++){
            tmp=curr->next;
            curr->next=rprev;
            rprev=curr;
            curr=tmp;
        }
        tmp=curr->next;
        curr->next=rprev;
        prev->next=curr;
        rtail->next=tmp;
        return nil->next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tmp=head;
        int n=0;
        while(tmp!=NULL) n++, tmp=tmp->next;
        for(int i=1; i+k-1<=n; i+=k){
            head=reverseBetween(head, i, i+k-1);
        }
        return head;
    }
};