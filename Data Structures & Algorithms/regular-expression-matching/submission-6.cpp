
class Solution {
public:
    bool solve(string& str, string& pattern, int i, int j,
               vector<vector<int>>& dp) {

        if (i < 0 && j < 0) {
            return true;
        }

        if (j < 0) {
            return false;
        }

        if (i < 0) {
            if (j >= 1 && pattern[j] == '*') {
                return solve(str, pattern, i, j - 2, dp);
            }
            return false;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool match = (str[i] == pattern[j] || pattern[j] == '.');

        if (pattern[j] == '*') {

            bool zeroOccurrence =
                solve(str, pattern, i, j - 2, dp);

            bool oneOrMoreOccurrence = false;

            if (j >= 1 &&
                (str[i] == pattern[j - 1] || pattern[j - 1] == '.')) {

                oneOrMoreOccurrence =
                    solve(str, pattern, i - 1, j, dp);
            }

            return dp[i][j] =
                zeroOccurrence || oneOrMoreOccurrence;
        }

        if (match) {
            return dp[i][j] =
                solve(str, pattern, i - 1, j - 1, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(s, p, n - 1, m - 1, dp);
    }
};
