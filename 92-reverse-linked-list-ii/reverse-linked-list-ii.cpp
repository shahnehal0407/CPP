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
        ListNode* store=head;
        ListNode* prev=NULL;
        int c=1;
       
        while(c<left){prev=store;store=store->next; c++;}
        ListNode* p=NULL;
        ListNode* q=NULL;
        ListNode* r=store;
        while(c<=right){
            p=q;
            q=r;
            r=r->next;
            q->next=p;
            c++;
        }
        if (prev != NULL) {
            prev->next = q;
        } else {
            head = q;
        }
        store->next=r;
        return head;

    }
};