class Solution(object):
    def uncommonFromSentences(self, A, B):
        counter = collections.Counter((A + " " + B).split())
        return [ c for c in counter if counter[c] ==1 ]
        
