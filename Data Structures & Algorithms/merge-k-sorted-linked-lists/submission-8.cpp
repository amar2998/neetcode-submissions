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
    ListNode* mergeTwoList(ListNode* head1,ListNode* head2){
        ListNode* curr1=head1;
        ListNode* curr2=head2;
        ListNode head(0);
        ListNode* tail=&head;
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }

        while(curr1 && curr2){
            if(curr1->val <= curr2->val){
                tail->next=curr1;
                tail=tail->next;
                curr1=curr1->next;
            }else{
                tail->next=curr2;
                tail=tail->next;
                curr2=curr2->next;
            }
        }
        tail->next=curr1 ? curr1:curr2;
        return head.next;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0){
            return NULL;
        }
       ListNode* head=lists[0];
       for(int i=1;i<lists.size();i++){
        ListNode* head2=lists[i];
        head=mergeTwoList(head,head2);
       } 
       return head;
    }
};
