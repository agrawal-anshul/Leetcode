# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        if not list2:
            return list1
        
        h1 = list1
        h2 = list2
        dummy = ListNode(0)
        curr = dummy
        while h1 and h2:
            if h1.val <= h2.val:
                curr.next = h1
                h1 = h1.next
            else:
                curr.next = h2
                h2 = h2.next
            curr = curr.next
        
        if h1:
            curr.next = h1
        else:
            curr.next = h2
            
        return dummy.next