class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        
        costs.sort(reverse = True, key = lambda x: abs(x[0]-x[1]))
        
        cost = 0 
        
        A = len(costs)//2
        B = len(costs)//2
        
        for c in costs:
            
            costA = c[0]
            costB = c[1]
            
            if (costA < costB and A) or not B:
                cost += costA
                A-=1
            else:
                cost += costB
                B-=1
        return cost
                
