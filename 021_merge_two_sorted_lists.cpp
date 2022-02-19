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
        ListNode* head = NULL;
        ListNode* curr = NULL;
        if(list1 == NULL){ return list2;}
        else if(list2 == NULL){return list1;}
        
        if(list1->val < list2->val){
            head = list1;
            curr = head;
            list1 = list1->next;
        }
        else{
            head = list2;
            curr = head;
            list2 = list2->next;
        }
        
        while(list1 != NULL || list2 != NULL){
            if(list1 == NULL){
                curr->next = list2;
                list2=list2->next;
            }
            else if(list2 == NULL){
                curr->next = list1;
                list1=list1->next;
            }
            else if(list1->val == list2->val){
                curr->next = list1;
                list1 = list1->next;
                curr = curr->next;
                curr->next = list2;
                list2 = list2->next;
            }
            else if(list1->val < list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else if(list1->val > list2->val){
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
            
        }
        return head;
    }
};