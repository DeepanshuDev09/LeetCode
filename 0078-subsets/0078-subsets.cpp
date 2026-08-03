class Solution {
    void generateSubset(vector<vector<int>>& result, vector<int>& nums, vector<int> curr, int next){
        if (next >= nums.size()){
            // result.push_back(curr);
            return;
        }

        curr.push_back(nums[next]);

        result.push_back(curr);

        next++;
        generateSubset(result, nums, curr, next);
        curr.pop_back();
        generateSubset(result, nums, curr, next);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        result.push_back({});
        
        generateSubset(result, nums, curr, 0);

        return result;   
    }
};