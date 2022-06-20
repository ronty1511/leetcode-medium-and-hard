class Solution {
public:
    vector<string> res;
    void dfs(int n, int o, int c, string str) {
        if (c == n) {
            res.push_back(str);
            return;
        }
        if (o > c) {
            if (o < n) {
                str += '(';
                dfs(n, o + 1, c, str);
                str.pop_back();
            }            
            str += ')';
            dfs(n, o, c + 1, str);
        } else {
            str += '(';
            dfs(n, o + 1, c, str);
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }
};