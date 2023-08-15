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
        if(head==NULL) return NULL;
        vector<int>v1,v2;
        while(head){
            if(head->val<x) v1.push_back(head->val);
            else v2.push_back(head->val);
            head=head->next;
        }
        
        for(auto i:v2)v1.push_back(i);
        ListNode *root=new ListNode(0);
        ListNode *temp=root;
        for(auto i:v1){
            ListNode *T=new ListNode(i);
            temp->next=T;
            temp=temp->next;
        }
        return root->next;
    }
};
