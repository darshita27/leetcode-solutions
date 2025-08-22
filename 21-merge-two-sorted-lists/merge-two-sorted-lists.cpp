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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
        ListNode* ptr1= list1;
        ListNode* ptr2= list2;
        ListNode* dummy= new ListNode(-1);
        ListNode* ans= dummy;
        while(ptr1!=NULL && ptr2!= NULL){
            if(ptr1->val < ptr2->val){
                dummy->next= ptr1;
                ptr1=ptr1->next;
                dummy=dummy->next;
            }else{
                dummy->next= ptr2;
                ptr2=ptr2->next;
                dummy=dummy->next;
            }
        }
        if(ptr1==NULL && ptr2!=NULL){
            dummy->next= ptr2;
        }else if(ptr1!=NULL && ptr2==NULL){
            dummy->next=ptr1;
        }
        return ans->next;
    }
};