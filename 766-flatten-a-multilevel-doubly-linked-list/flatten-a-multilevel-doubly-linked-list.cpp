/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* dfs(Node*  node){
        Node* cur=node;
         Node* last = nullptr;
         while(cur){
         Node* next=cur->next;
         if(cur->child){
            Node* child_head=cur->child;
            Node* child_tail=dfs(cur->child);
            cur->next=child_head;
            child_head->prev=cur;
            cur->child=nullptr;
                if (next) {
                    child_tail->next = next;
                    next->prev = child_tail;
                }
            last=child_tail;

         }
         else last=cur;
         cur=next;
         }

        return last;
    }
         





    Node* flatten(Node* head) {
        if(!head) return nullptr;
        dfs(head);

        return head;

    }
};