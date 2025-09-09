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
    ListNode* find_middle(ListNode *head){
        ListNode *slow=head, *fast=head, *pslow;
        pslow=head;
        while(fast!=NULL){
            if(fast->next==NULL) return slow;
            pslow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pslow->next=NULL;
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode *curr=head, *prev=NULL, *tmp=NULL;
        while(curr->next!=NULL){
            tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        curr->next=prev;
        return curr;
    }
    void reorderList(ListNode* head) {
        ListNode *mid = find_middle(head);
        ListNode *tail = reverse(mid);
        ListNode *tmp;
        while(head!=NULL){
            tmp=head->next;
            head->next=tail;
            tail=tail->next;
            head->next->next=tmp;
            head=tmp;
        }
        return;
    }
};