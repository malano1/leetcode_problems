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
        if(l1 || l2){
            //Remainder and Quotient variables
            int r = 0;
            int q = 0;
            //If ListNode l1 does not exists
            if(!l1){
                r = (l2->val)%10;
                q = (l2->val)/10;
                //Check for 1 carrying over & add it to next digit calculation
                if(q > 0 && l2->next){
                    l2->next->val = l2->next->val + q;
                }
                //If not next node, create one to carry 1
                else if(q > 0){
                    l2->next = new ListNode(q);
                }
                return new ListNode(r,addTwoNumbers(nullptr,l2->next));
            }
            //If ListNode l2 does not exists
            else if(!l2){
                r = (l1->val)%10;
                q = (l1->val)/10;
                //Check for 1 carrying over & add it to next digit calculation
                if(q > 0 && l1->next){
                    l1->next->val = l1->next->val + q;
                }
                //If not next node, create one to carry 1
                else if(q > 0){
                    l1->next = new ListNode(q);
                }
                return new ListNode(r,addTwoNumbers(l1->next,nullptr));
            }
            else{
                r = (l1->val + l2->val)%10;
                q = (l1->val + l2->val)/10;
                //Check for 1 carrying over & add it to next digit calculation
                if(q > 0 && l1->next){
                    l1->next->val = l1->next->val + q;
                }
                //If not next node, create one to carry 1
                else if(q > 0){
                    l1->next = new ListNode(q);
                }
                return new ListNode(r,addTwoNumbers(l1->next,l2->next));
            }
        }
        return nullptr;
    }
};