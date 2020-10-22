class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        row3 = set("ZXCVBNMzxcvbnm")
        row1 = set("QWERTYUIOPqwertyuiop")
        row2 = set("ASDFGHJKLasdfghjkl")
        
        def f(word):
            s = set(word)
            f1 = s & row1
            f2 = s & row2
            f3 = s & row3
            
            return (f1 and not f2 and not f3) or (f2 and not f1 and not f3) or (f3 and not f1 and not f2)
        
        return filter(f, words)
