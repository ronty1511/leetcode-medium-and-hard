class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stk = []
        for ch in s:
            if len(stk):
                if stk[-1][0] == ch:
                    stk.append([ch, stk[-1][1] + 1])
                else:
                    stk.append([ch, 1])
                if stk[-1][1] == k:
                    x = 0
                    while x < k:
                        stk.pop()
                        x += 1
            else:
                stk.append([ch, 1])
        res = ""
        for idx, val in enumerate(stk):
            res += val[0]
        return res