# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def reverse_segment(start, end):
            prev, curr = None, start
            while curr != end:
                next_node = curr.next
                curr.next = prev
                prev = curr
                curr = next_node
            return prev

        dummy = ListNode(0)
        dummy.next = head
        prev_group_end = dummy

        while True:
            kth_node = prev_group_end
            for _ in range(k):
                kth_node = kth_node.next
                if not kth_node:
                    return dummy.next
            
            # Reverse the k nodes
            group_start = prev_group_end.next
            next_group_start = kth_node.next
            kth_node.next = None
            new_group_head = reverse_segment(group_start, None)

            # Connect the reversed group back to the main list
            prev_group_end.next = new_group_head
            group_start.next = next_group_start
            prev_group_end = group_start
