// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        if (!head) return head;

        // 1) Reverse so LSD comes first.
        ListNode* rev = reverse(head);

        // 2) Walk, doubling digits with carry.
        int carry = 0;
        ListNode* cur = rev;
        ListNode* prev = nullptr;
        while (cur) {
            int sum = cur->val * 2 + carry;
            cur->val = sum % 10;
            carry   = sum / 10;
            prev = cur;
            cur = cur->next;
        }
        if (carry) prev->next = new ListNode(carry);  // possible new most-significant digit

        // 3) Reverse back to original order.
        return reverse(rev);
    }
};
