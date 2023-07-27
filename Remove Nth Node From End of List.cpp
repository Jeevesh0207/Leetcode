class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ans=head;
        ListNode *temp=head;
        int N=0;
        while(temp){
            N++;
            temp=temp->next;
        }
        if(N==1 && n==1) return NULL;
        int k=N-n;
        if(k==0) return ans->next;
        while(head){
            k--;
            if(head && k==0){
                ListNode *T=head;
                T->next=head->next->next;
            }
            head=head->next;
            
        }
        return ans;
    }
};
