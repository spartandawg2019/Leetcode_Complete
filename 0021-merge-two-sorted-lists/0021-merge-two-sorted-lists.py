# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # Create a dummy head node
        dummy = ListNode(-1)
        current = dummy
        
        # Iterate through both lists until one of them becomes empty
        while l1 and l2:
            # If the value in l1 is smaller, append it to the merged list and move to the next node in l1
            if l1.val < l2.val:
                current.next = l1
                l1 = l1.next
            # Otherwise, do the same for l2
            else:
                current.next = l2
                l2 = l2.next
            # Move to the next node in the merged list
            current = current.next
        
        # Append the remaining nodes of the non-empty list to the merged list
        current.next = l1 or l2
        
        return dummy.next
