class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        res = 0
        sz = len(nums)
        nums.sort()
        i, j = 0, len(nums) - 1
        while i < j:
            sum = nums[i] + nums[j]
            if sum > k:
                j -= 1
            elif sum < k:
                i += 1
            else:
                res += 1
                i += 1
                j -= 1
        return res