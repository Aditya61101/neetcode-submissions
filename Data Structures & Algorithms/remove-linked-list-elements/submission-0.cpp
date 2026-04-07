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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy=ListNode(-1);
        ListNode *tail=&dummy;

        ListNode*curr=head;
        while(curr) {
            if(curr->val==val) {
                tail->next=curr->next;
            } else {
                tail->next=curr;
                tail=tail->next;
            }
            curr=curr->next;
        }
        return dummy.next;
    }
};