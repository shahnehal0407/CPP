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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>store1;
        vector<int>store2;

        while(l1!=NULL){
            store1.push_back(l1->val);
            l1=l1->next;
        }
                while(l2!=NULL){
            store2.push_back(l2->val);
            l2=l2->next;
        }
                int i = store1.size() - 1;
        int j = store2.size() - 1;
        int carry = 0;

        ListNode* head = NULL;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += store1[i--];
            if (j >= 0) sum += store2[j--];

            carry = sum / 10;
            int digit = sum % 10;

            ListNode* node = new ListNode(digit);
            node->next = head;
            head = node;
        }

        return head;
    



    }
};