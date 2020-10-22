# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        a = []
        while head is not None:
            a.append(head.val)
            head = head.next
        ans = []
        stack = []
        for v in a[::-1]:
            
            while len(stack)>0 and stack[-1] <= v:
                stack.pop()
                
            if len(stack) == 0:
                ans.append(0)
                stack.append(v)
            else:
                ans.append(stack[-1])
                stack.append(v)
        
        return ans[::-1]
            

