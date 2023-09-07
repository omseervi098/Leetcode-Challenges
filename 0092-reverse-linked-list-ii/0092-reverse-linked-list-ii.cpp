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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* subans=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return subans;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int n=right-left+1;
        ListNode* prevleft=NULL,*prevRight=NULL,*h=head;
        while(head->next!=NULL and left>1){
            prevleft=head;
            head=head->next;
            left--;
        }
        ListNode *leftst=head;
        while(head!=NULL and n-->0){
            prevRight=head;
            head=head->next;
        }
        prevRight->next=NULL;
        ListNode* newLeft=reverse(leftst);
        leftst->next=head;
        if(prevleft)
            prevleft->next=newLeft;
        else h=newLeft;
        return h ;
    }
};