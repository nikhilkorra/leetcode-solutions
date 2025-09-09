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

#define INF 10001;

// auto compare = [](ListNode* a, ListNode* b){
//     return a->val < b->val;
// };

struct compare{
    bool operator()(const ListNode* a, const ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        int k = lists.size();
        for(int i = 0; i < k; i++){
            if(lists[i] != NULL)
                pq.push(lists[i]);
        }
        ListNode *nil = new ListNode(0);
        ListNode *curr = nil;
        while(pq.size()){
            ListNode* top = pq.top();
            pq.pop();
            if(top->next != NULL){
                pq.push(top->next);
                top->next = NULL;
            }
            curr->next = top;
            curr = curr->next;
        }
        return nil->next;
    }
};