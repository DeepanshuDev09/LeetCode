class Solution {
    void solve(vector<vector<int>>& result, vector<int> curr, int next, 
                vector<int> nums)
    {
        if (next >= nums.size()) return;

        curr.push_back(nums[next]);

        auto it = find(result.begin(), result.end(), curr);
        if (it == result.end()) result.push_back(curr);

        solve(result, curr, next+1, nums); 
        curr.pop_back();
        solve(result, curr, next+1, nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        result.push_back(curr);

        sort(nums.begin(), nums.end());

        solve(result, curr, 0, nums);

        return result;
    }
};