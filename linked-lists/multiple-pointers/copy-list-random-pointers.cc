/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *x, *y, *tmp;
        x=head;
        while(x){
            // cout<<x->val<<' '<<&(x->random)<<", ";
            y = new Node(x->val);
            tmp = x->next;
            x->next = y;
            y->next = tmp;
            x=tmp;
        }
        cout<<endl;
        x = head;
        tmp = NULL;
        if(x) tmp = x->next;
        while(x){
            y = x->next;
            if(x->random) y->random = x->random->next;
            x = y->next;
        }
        x = head;
        while(x){
            y = x->next;
            // cannot delete as you traverse as random may point to previous nodes
            // if(x->random) y->random = x->random->next;
            x->next = y->next;
            if(y->next) y->next = y->next->next;
            x = x->next;
            // cout<<y->val<<' '<<&(y->random)<<", ";
        }
        // cout<<endl;
        y = tmp;
        return y;
    }
};