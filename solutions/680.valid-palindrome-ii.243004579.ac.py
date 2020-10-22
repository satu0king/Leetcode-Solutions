class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        if s == s[::-1]:
            return True
        n = len(s)
        for i in range(n):
            if s[i] != s[n-i-1]:
                return (s[:i] + s[i+1:]) == (s[:i] + s[i+1:])[::-1] or (s[:n-i-1] + s[n-i:]) == (s[:n-i-1] + s[n-i:])[::-1]
