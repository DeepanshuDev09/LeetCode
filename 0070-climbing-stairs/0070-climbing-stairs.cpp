class Solution {
    int solve(vector<int>& dp, int currSteps, int n) {
        if (currSteps == n)
            return 1;

        if (currSteps > n)
            return 0;

        if (dp[currSteps] != -1)
            return dp[currSteps];

        return dp[currSteps] =
            solve(dp, currSteps + 1, n) +
            solve(dp, currSteps + 2, n);
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(dp, 0, n);
    }
};