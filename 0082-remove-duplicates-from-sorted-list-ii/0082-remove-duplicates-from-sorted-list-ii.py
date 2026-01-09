# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head

        prev = dummy
        curr = head

        while curr:
            # check if curr val is duplicated
            if curr.next and curr.val==curr.next.val:
                duplicate_value = curr.val

                # skip all duplicates
                while curr and curr.val == duplicate_value:
                    curr = curr.next
                
                prev.next = curr
            else:
                # current note is unique move prev forward
                prev = curr
                curr = curr.next
        return dummy.next
