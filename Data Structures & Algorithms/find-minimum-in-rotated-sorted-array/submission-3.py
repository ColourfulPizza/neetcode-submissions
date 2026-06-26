class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        n = len(nums)
        r = n
        if nums[0] < nums[r - 1]:
            return nums[0]
        if n == 1:
            return nums[0]
        while r - l > 1:
            m = int((r + l) /2)
            if nums[m] > nums[l]:
                l = m
            else:
                r = m
        return nums[r]
            