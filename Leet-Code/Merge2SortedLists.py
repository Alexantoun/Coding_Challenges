# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        list3 = ListNode()
        head = list3

        if list1 == None and list2 == None:
            return None
        
        while(list1!=None or list2!=None):
            if list1!=None and list2!=None:
                if list1.val <= list2.val:
                    list3.val = list1.val
                    list1=list1.next  
                else:
                    list3.val=list2.val
                    list2=list2.next
            elif list1!=None and list2==None:
                list3.val = list1.val
                list1=list1.next
            elif list2!=None and list1==None:
                list3.val = list2.val
                list2=list2.next
            else:
                list3 = None
            list3.next=ListNode()
            list3 = list3.next
        
        list3 = head
        while list3.next.next != None:
            list3 = list3.next
        list3.next = None    
        
        return head
                
        
        