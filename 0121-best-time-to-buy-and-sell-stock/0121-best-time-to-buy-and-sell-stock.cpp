class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int result = 0;
        int i = 0;

        for (int j = 1; j<nums.size(); j++){
            int curr = nums[j] - nums[i];
            result = max(result, curr);
            if (curr < 0) i = j;
        }

        return result;
    }
};