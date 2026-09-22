class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));

        for (int col = m-1; col>=0; col--){
            for (int row = n-1; row>=0; row--){

                if (row + 1 < n && col + 1 < m){
                    dp[col][row] = dp[col+1][row] + dp[col][row+1];
                }
                else if (row + 1 < n){
                    dp[col][row] = dp[col][row+1];
                }
                else if (col + 1 < m){
                    dp[col][row] = dp[col+1][row];
                }
                else {
                    dp[col][row] = 1;
                }
            }
        }

        return dp[0][0];
    }
};