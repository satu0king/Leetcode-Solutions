class Solution:
    def isRobotBounded(self, instructions):
        """
        :type instructions: str
        :rtype: bool
        """
        #up, left, down, right
        dir, start, d = ([-1, 0], [0, -1], [1, 0], [0, 1]), [0,0], 0
        for i in range(4):
            for x in instructions:
                if x == "G":
                    start[0] += dir[d][0]
                    start[1] += dir[d][1]
                if x == "L": d = (d + 1) % 4 
                if x == "R": d = (d - 1) % 4
        return True if start == [0,0] else False 
