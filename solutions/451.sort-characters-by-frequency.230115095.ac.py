class Solution:
    def frequencySort(self, s: str) -> str:
        return "".join(map(lambda x: x[0]*x[1], sorted(collections.Counter(s).items(), key= lambda x:x[1], reverse = True)))
        
        
