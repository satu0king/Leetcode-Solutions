class FreqStack:

    def __init__(self):
        self.stack = [[]]
        self.map = dict()

    def push(self, x: int) -> None:
        if x not in self.map:
            self.stack[0].append(x)
            self.map[x] = 0
        else:
            self.map[x]+=1
            i = self.map[x]
            if len(self.stack) <= i:
                self.stack.append([])
            self.stack[i].append(x)

    def pop(self) -> int:
        c = self.stack[-1].pop()
        if len(self.stack[-1]) == 0:
            self.stack.pop()
            
        self.map[c]-=1
        
        return c


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()
