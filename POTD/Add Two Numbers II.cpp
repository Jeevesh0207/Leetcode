//----------------Naive Approach ----------------//

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>v1,v2,v3;
        while(l1!=NULL){
            v1.push_back(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            v2.push_back(l2->val);
            l2=l2->next;
        }
        ListNode* x= new ListNode(NULL);
        ListNode* ans=x;
        int i=v1.size()-1,j=v2.size()-1;
        int carry=0;
        while(i>=0 || j>=0 || carry!=0){
            int d=0;
            if(carry!=0) d+=carry;
            if(i>=0){
                d+=v1[i];
                i--;
            }
            if(j>=0){
                d+=v2[j];
                j--;
            }
            int num=d%10;
            carry=d/10;
            v3.push_back(num);
        }
        for(int i=v3.size()-1;i>=0;i--){
            ListNode *temp=new ListNode(v3[i]);
            x->next=temp;
            x=x->next;
        }
        return ans->next;
    }
};

//----------------Optimal Approach ----------------//

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
    ListNode* Reverse(ListNode* head){
        ListNode* prev=NULL;
        while(head){
            ListNode* Next=head->next;
            head->next=prev;
            prev=head;
            head=Next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=Reverse(l1);
        l2=Reverse(l2);
        int carry=0;
        ListNode *x=new ListNode(NULL);
        ListNode *ans=x;
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
            if(carry!=0) d+=carry;
            int num=d%10;
            carry=d/10;
            ListNode *temp=new ListNode(num);
            x->next=temp;
            x=x->next;
        }
        ans=ans->next;
        return Reverse(ans);
    }
};
