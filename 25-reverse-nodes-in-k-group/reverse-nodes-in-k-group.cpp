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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* Node=head;
         ListNode* prev=NULL;
         ListNode* temp=head;
        int n=0, x=k;
        while(Node!=NULL){
         n++;
         Node=Node->next;
        }
        n /=k;
        Node=head;
        if(!n) return head;

        while(x--){
             ListNode* front=temp->next;
             temp->next=prev;
             prev=temp;
             temp=front;
        }
        head=prev;
        n--;

while(n--){
    x=k;
    prev=NULL;

    while(x--){
             ListNode* front=temp->next;
             temp->next=prev;
             prev=temp;
             temp=front;
        }
        Node->next=prev;
        while(Node->next)Node=Node->next;
}

    Node->next=temp;
   return head;
    }
};
//https://leetcode.com/problems/reverse-nodes-in-k-group/solutions/5943080/iterative-n-simple-solution-beats-100-tc-o-n-sc-o-1/