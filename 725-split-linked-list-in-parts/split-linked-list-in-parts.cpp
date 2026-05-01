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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,nullptr);
        ListNode * temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }

        int p=n/k;
        int e=n%k;
        ListNode * curr=head;
        for(int i=0;i<k;i++){
            if(!curr)break;
            ans[i]=curr;

            int a=p+ (e>0?1:0);
            e--;

            for(int j=1;j<a;j++){
                curr=curr->next;
            }

            ListNode * store=curr->next;
            curr->next=NULL;
            curr=store;
        }

        return ans;
    }
};