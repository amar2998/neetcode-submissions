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
        int length=0;
        while(curr){
            curr=curr->next;
            length++;
        }

        curr=head;
        ListNode* prev=NULL;
        while(curr){
            if(n==length){
                if(curr==head){
                    return head->next;
                }           
                prev->next=curr->next;
                curr->next=NULL;
                break;
            }
            else{
                prev=curr;
                curr=curr->next;
                length--;
            }
        }
        return head;
    }
};
