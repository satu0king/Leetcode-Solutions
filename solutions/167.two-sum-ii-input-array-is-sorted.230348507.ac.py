class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        
        for i, n in enumerate(numbers):
            j = bisect.bisect(numbers, target - n) - 1
            if numbers[j] == target - n and j!=i:
                return (i+1, j+1)
            
        
