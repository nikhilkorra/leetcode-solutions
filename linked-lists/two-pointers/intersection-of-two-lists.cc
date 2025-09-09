/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a, *b;
        a=headA;
        b=headB;
        while(a!=b){
            if(a==NULL) a=headB;
            if(b==NULL) b=headA;
            if(a==b) return a; // [3], [2,3]
            a=a->next;
            b=b->next;
        }
        return a;
    }
};