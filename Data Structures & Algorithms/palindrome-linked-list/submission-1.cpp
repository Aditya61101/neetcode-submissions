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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        // find the middle of ll
        ListNode *f=head, *s=head;
        while(f->next && f->next->next) {
            s=s->next;
            f=f->next->next;
        }
        s=s->next;
        ListNode *p=nullptr;
        // reverse second half
        while(s){
            ListNode *next=s->next;
            s->next=p;
            p=s;
            s=next;
        }
        // checking pair wise
        ListNode* c=head;
        while(p) {
            if(c->val!=p->val) return false;
            c=c->next;
            p=p->next;
        }
        return true;

    }
};