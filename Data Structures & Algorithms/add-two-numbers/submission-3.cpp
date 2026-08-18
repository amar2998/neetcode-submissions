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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode* curr3=NULL;
        ListNode* head=NULL;
        while(curr1 && curr2){
            int sum=curr1->val+curr2->val + carry;
            int nodeValue=sum%10;
            carry=sum/10;
            if(curr1==l1 ){
                head=new ListNode(nodeValue);
                curr3=head;
                curr1=curr1->next;
                curr2=curr2->next;
                continue;
            }
            ListNode* node=new ListNode(nodeValue);
            curr3->next=node;
            curr3=curr3->next;
            curr1=curr1->next;
            curr2=curr2->next;
        }

        while(curr1){
            int sum=curr1->val+ carry;
            int nodeValue=sum%10;
            carry=sum/10;
            ListNode* node=new ListNode(nodeValue);
            curr3->next=node;
            curr3=curr3->next;
            curr1=curr1->next;
        }
        while(curr2){
            int sum=curr2->val+ carry;
            int nodeValue=sum%10;
            carry=sum/10;
            ListNode* node=new ListNode(nodeValue);
            curr3->next=node;
            curr3=curr3->next;
            curr2=curr2->next;
        }
        while(carry!=0){
            int sum= carry;
            int nodeValue=sum%10;
            carry=sum/10;
            ListNode* node=new ListNode(nodeValue);
            curr3->next=node;
            curr3=curr3->next;
        }
        return head;
        
    }
};
