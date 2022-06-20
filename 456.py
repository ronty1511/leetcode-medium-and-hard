import sys
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        # Following 2 3 1 approach from reverse
        sz = len(nums)
        stk = []
        second = -sys.maxsize - 1
        for i in range(sz - 1, -1, -1):
            if nums[i] < second:
                return True
            while len(stk) and stk[-1] < nums[i]:
                second = stk[-1]
                stk.pop()
            stk.append(nums[i])
        return False