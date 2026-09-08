class Solution {
public:
    int t[1001][1001];

    int solve(string s1, string s2, int n) {
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }

                else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        return t[n][n];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();

        string s2 = s;

        reverse(s.begin(), s.end());

        return solve(s, s2, n);
    }
};