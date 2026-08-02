class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        cnt = len(nums)

        for i in range(cnt):
            for j in range(i):
                if nums[i] + nums[j] == target:
                    return [j,i]
        
        return 
        
