class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        return num if num < 10 else (num-10)%9 + 1
    
    
        
