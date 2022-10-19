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
        ListNode* l3 = new ListNode;
        ListNode* l3Target = l3;
        int excess = 0;
        
        l3Target->val = l2->val + l1->val;
        while (l3Target->val >= 10){
            excess++;
            l3Target->val -= 10;
        }
        l1=l1->next;
        l2 = l2->next;
        while((l1 != NULL || l2 != NULL) || excess != 0 )
        {
            l3Target->next = new ListNode;
            l3Target = l3Target->next;  
            l3Target->val += excess;
            excess = 0;
            if(l1 != NULL)
            {
                l3Target->val += l1->val;
                l1 = l1->next;  
            }
            if (l2 != NULL)
            {
                l3Target->val += l2->val;
                l2 = l2->next; 
            }
            while (l3Target->val >= 10){
                excess++;
                l3Target->val -= 10;
            }
        }

        return l3;
    }
};