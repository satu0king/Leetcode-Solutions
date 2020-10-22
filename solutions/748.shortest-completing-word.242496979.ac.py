class Solution(object):
    def shortestCompletingWord(self, licensePlate, words):
        words.sort(key = len)
        
        s = collections.Counter()
        for c in licensePlate.lower():
            if c.isalpha(): s[c]+=1
        
        for word in words:
            if len(s - collections.Counter(word.lower())) == 0:
                return word
        return ""
        
