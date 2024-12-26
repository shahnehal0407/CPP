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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* Node=head;
         if(head==NULL || head->next==NULL){
            return head;
        }
        int total=0;
        while(Node){
            Node=Node->next;
          total++;
        }
        Node=head;
    ListNode* temp;
    int n=1;
    k=k%total;
       if(k==0){
            return head;
        }
     while(Node->next!=NULL){
        if(n==total-k)temp=Node;
       Node=Node->next; n++;
     }
      Node->next=head;
      head=temp->next;
      temp->next=NULL;
     return head;
    }
};