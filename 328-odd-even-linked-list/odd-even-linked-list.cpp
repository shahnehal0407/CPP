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
 ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *headodd = head;
        ListNode *headeven = head->next;
        ListNode *even = headeven;

        int count = 1;
       
        while(headodd->next && headeven->next) {   
            if(count % 2 == 1) {
                headodd->next = headodd->next->next;
                headodd = headodd->next;
            } else {
                headeven->next = headeven->next->next;
                headeven = headeven->next;
            }
            count++;
        }

        headodd->next = even;
        headeven->next = nullptr; 

        return head;
    }
};