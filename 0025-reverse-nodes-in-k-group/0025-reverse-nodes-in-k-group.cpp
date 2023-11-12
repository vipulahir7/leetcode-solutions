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
 int lengthOfLinkedList(ListNode* &head) {

    ListNode* temp = head;

    int length = 0;

    while(temp) {

        length ++;

        temp = temp -> next;

    }

    return length;

}
    ListNode* reverseKGroup(ListNode* head, int k) {
    int length = lengthOfLinkedList(head);

    if(head==NULL||k>length){
        return head;
    }


    ListNode* next=NULL;
    ListNode* curr=head;
    ListNode* prev=NULL;
    int count=0;

    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;   
        count++;
    }

    if(next!=NULL){
        head->next=reverseKGroup(next,k);
    }

    return prev;
    }
};