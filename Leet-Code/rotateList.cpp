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
 #include <deque>
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;

        deque<ListNode*> queue;
        ListNode* current = head;

        while(current != NULL)
        {
            queue.push_back(current);
            current = current->next;
        }
        if(queue.size() == 1)
            return head;

        else
        {
            int rotations = k % queue.size();
            for(int rotation = 0; rotation < rotations; ++rotation)
            {
                current = queue.back();
                queue.pop_back();
                queue.back()->next = NULL;

                current->next = queue.front();
                queue.push_front(current);
            }
            return queue.front();
        }
    }
};