class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l = len(heights)
        ans = 0
        for i in range(l):
            for j in range(i):
                area = min(heights[j],heights[i]) * (i - j)
                ans = max(ans, area)
        
        return ans
