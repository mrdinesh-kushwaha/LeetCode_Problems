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
    ListNode* reverseLL(ListNode* head){
        if(head==NULL)
        return head;

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=head;
        while(curr!=NULL){
            Next= Next->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
    ListNode* additionLL(ListNode* head1){
        if(head1==NULL)
        return head1;

        int carry=0;
        ListNode* temp=head1;
        ListNode* anshead=nullptr;
        ListNode* anstail=nullptr;

        while(temp){
            int sum=temp->val+carry;
            int digit=sum%10;
            carry=sum/10;
          ListNode* newNode=new ListNode(digit);

            if(anshead==nullptr)
            {
                anshead=newNode;
                anstail=newNode;
            }
            else
            {
                anstail->next=newNode;
                anstail=newNode;
            }
            temp=temp->next;
        }

        while(carry!=0){
            int sum=carry;
            int digit=sum%10;
            carry=sum/10;
            ListNode* newNode =new ListNode(digit);

            anstail->next=newNode;
            anstail=newNode;
        }
        return anshead;
    }
    ListNode* doubleIt(ListNode* head) {

        if(head==NULL)
        return head;
        ListNode* head1=head;
        ListNode* head2=head;
        while(head2){
            head2->val=2*head2->val;
            head2=head2->next;
        }
        ListNode* head3=reverseLL(head1);
        ListNode* ans=additionLL(head3);
        ListNode* ans1=reverseLL(ans);
        return ans1;
        
    }
};