class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        minr = [0] * n
        maxl = [0] * n
        minr[n - 1] = nums[n - 1]
        maxl[0] = nums[0]
        for i in range(1, n):
            maxl[i] = max(maxl[i - 1], nums[i])
        for i in range(n - 2, -1, -1):
            minr[i] = min(minr[i + 1], nums[i])
        i, j = 0, n - 1
        while i < n and nums[i] == maxl[i] and nums[i] == minr[i]:
            i += 1
        while j >= 0 and nums[j] == minr[j] and nums[j] == maxl[j]:
            j -= 1
        if i < j:
            return j - i + 1
        return 0