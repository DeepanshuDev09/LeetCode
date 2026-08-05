class Solution {
    void solve(vector<vector<int>>& result, int end, int curr, vector<int> currArr,
                int sum, int k, int n)
    {
        if (curr > end) return;

        sum = sum + curr;
        currArr.push_back(curr);
        if (sum == n && currArr.size() == k) result.push_back(currArr);

        if (sum > n) return;

        solve(result, end, curr+1, currArr, sum, k, n);
        sum = sum - curr;
        currArr.pop_back();
        solve(result, end, curr+1, currArr, sum, k, n);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (k > n) return result;

        int end = 9;

        solve(result, end, 1, {}, 0, k, n);

        return result;
    }
};