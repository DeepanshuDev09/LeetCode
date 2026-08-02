class Solution {
    void solve(vector<int>& arr, int index, int sum, int target, vector<int>& currArr, vector<vector<int>>& result){

        if (sum == target ) {
            auto it = find(result.begin(), result.end(), currArr);
            if (it == result.end()) result.push_back(currArr);
            return;
        }
        if (sum > target || index >= arr.size()) return;

        currArr.push_back(arr[index]);

        solve(arr, index, sum + arr[index], target, currArr, result);

        currArr.pop_back();

        solve(arr, index + 1, sum, target, currArr, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currArr;

        for (int i = 0; i < candidates.size(); i++) {
            solve(candidates, i, 0, target, currArr, result);
        }

        return result;
    }
};