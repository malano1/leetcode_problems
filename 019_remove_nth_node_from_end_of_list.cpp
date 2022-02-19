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
        
        ListNode* temp = head;
        int numOfNodes = 0;
        // count
        while(temp != NULL){
            numOfNodes++;
            temp = temp->next;
        }
        temp = head;
        
        //base cases
        if(numOfNodes == 1){
            return nullptr;
        }
        else if(n == numOfNodes){
            head = head->next;
        }
        else if(n == 1){
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            temp->next = NULL;
        }
        else{   
            int count = 0;
            while(numOfNodes - count != n){
                temp = temp->next;
                count++;
            }

            temp->val = temp->next->val;
            temp->next = temp->next->next;
        }
        return head;
    }
};