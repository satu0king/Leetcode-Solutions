class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        return list(map(lambda x: list(map(lambda x: x^1, x[::-1])), A))
        
