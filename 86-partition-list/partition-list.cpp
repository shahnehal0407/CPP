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
    ListNode* partition(ListNode* head, int x) {
        vector<int>v;
        ListNode* temp=head;

        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>a;
        for(int i=0;i<v.size();i++){
            if(v[i]<x)a.push_back(v[i]);
        }

        for(int i=0;i<v.size();i++){
            if(v[i]>=x)a.push_back(v[i]);
        }
            int m=0;
            temp=head;
            while(temp!=NULL){
               temp->val=a[m];
               temp=temp->next;
                m++;
            }
 

        return head;

    }
};