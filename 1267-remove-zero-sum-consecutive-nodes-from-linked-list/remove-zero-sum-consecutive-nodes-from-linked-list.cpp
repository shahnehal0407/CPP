class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        int prefix = 0;
        ListNode* curr = dummy;

        // Pass 1: store last occurrence of prefix sum
        while (curr) {
            prefix += curr->val;
            mp[prefix] = curr;
            curr = curr->next;
        }

        // Pass 2: remove zero sum nodes
        prefix = 0;
        curr = dummy;

        while (curr) {
            prefix += curr->val;
            curr->next = mp[prefix]->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};