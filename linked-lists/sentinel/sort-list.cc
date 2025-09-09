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
    ListNode* findMiddle(ListNode *head){
        ListNode *slow, *fast, *pslow;
        fast=head;
        slow=head;
        pslow=slow;
        while(fast){
            if(fast->next==NULL) break;
            pslow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pslow->next=NULL;
        return slow;
    }
    ListNode* merge(ListNode* h1, ListNode *h2){
        ListNode *nil = new ListNode(-1000);
        ListNode *curr = nil;
        while(h1 && h2){
            if(h1->val <= h2->val){
                curr->next=h1;
                h1=h1->next;
            }
            else{
                curr->next=h2;
                h2=h2->next;
            }
            curr=curr->next;
        }
        if(h1) curr->next=h1;
        else curr->next=h2;
        return nil->next;
    }
    ListNode* mergeSort(ListNode* head){
        if(head->next==NULL) return head;
        ListNode *mid = findMiddle(head);
        head = mergeSort(head);
        mid = mergeSort(mid);
        return merge(head, mid);
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return head;
        return mergeSort(head);
    }
};