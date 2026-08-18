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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        int length=0;
        while(curr!=NULL){
            length++;
            curr=curr->next;
        }
        curr=head;
        while(curr!=NULL){
            if(length == n){
                if(head==curr){
                    return head->next;
                }
                prev->next=curr->next;
                curr->next=NULL;
                break;
            }else{
                prev=curr;
                curr=curr->next;
                length--;
            }
        }
        return head;
    }
};
