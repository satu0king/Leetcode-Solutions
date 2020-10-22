class Solution:
    def judgeCircle(self, moves: str) -> bool:
        d = collections.Counter(moves + "LRUD")
        return d["L"] == d["R"] and d["D"] == d["U"]
        
