class Solution {
public:
    void Run_Fast(){
        ios::sync_with_stdio(false); 
        cin.tie(0);                  
        cout.tie(0);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        Run_Fast();
        ListNode *num=new ListNode(0);
        ListNode *ans=num;
        int carry=0;
        while(l1 || l2 || carry!=0){
            int d=0;
            if(l1){
                d+=l1->val;
                l1=l1->next;
            }
            if(l2){
                d+=l2->val;
                l2=l2->next;
            }
            if(carry) d+=carry;
            int rem=d%10;
            carry=d/10;
            ListNode *temp=new ListNode(rem);
            num->next=temp;
            num=num->next;
        }
        return ans->next;
    }
};
