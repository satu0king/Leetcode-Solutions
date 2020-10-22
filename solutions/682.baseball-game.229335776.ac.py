class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        
        stack = []
        
        for op in ops:
            if op in ['C', 'D', '+']:
                if op == 'C':
                    stack.pop()
                elif op == 'D':
                    stack.append(stack[-1]*2)
                elif op == '+':
                    stack.append(stack[-1] + stack[-2])
            else:
                stack.append(int(op))
        
        return sum(stack)
        
