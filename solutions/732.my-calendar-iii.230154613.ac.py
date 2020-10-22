class MyCalendarThree:

    def __init__(self):
        self.bookings=[]
        
    

    def book(self, start: int, end: int) -> int:
        
        def ind(k):
            for i, booking in enumerate(self.bookings):
                if booking[0]>=k:
                    return i
            return len(self.bookings)
        
        self.bookings.insert(ind(start), (start, 1))
        self.bookings.insert(ind(end), (end, -1))
        
        l = [[0, 0]]
        for (d, v) in self.bookings:
            if d > l[-1][0]:
                l.append([d, v+l[-1][1]])
            else:
                l[-1][1]+=v
        return max(map(lambda x:x[1], l))
                            
        


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)
