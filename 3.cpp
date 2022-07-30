class Solution {
public:
    bool isValid(int cnt[]) {
        for (int i = 0; i < 128; i++) {
            if (cnt[i] > 1)
                return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int cnt[128] = {0};
        int n = s.size();
        int i = 0, res = 0;
        for (int j = 0; j < n; j++) {
            cnt[s[j]]++;
            while (!isValid(cnt))
                cnt[s[i++]]--;
            res = max(res, j - i + 1);
        }
        return res;
    }
};
