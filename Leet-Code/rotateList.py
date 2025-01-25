# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next 

from collections import deque

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None:
            return head

        current = head
        dq = deque()
        while current is not None:
            dq.append(current)
            current = current.next
   
        if len(dq) is 1:
            return head
        else:
            rotations = k % len(dq)
            for rotation in range(0, rotations):
                current = dq.pop()
                current.next = dq[0]
                dq.appendleft(current)
                dq[-1].next=None

        return dq[0]
                        