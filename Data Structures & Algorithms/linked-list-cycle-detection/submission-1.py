# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head is None:
            return False
        
        turtle = head
        hare = head

        while hare is not None and hare.next is not None:
            hare = hare.next.next
            turtle = turtle.next
            
            if turtle == hare:
                return True
        
        return False