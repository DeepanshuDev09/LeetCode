class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int maxAmount = 0;

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        for (int i = 0; i<n; i++){
            int curr = nums[i];
            if (i - 3 >= 0) curr = max(nums[i]+nums[i-2], nums[i]+nums[i-3]);
            if (i - 2 >= 0) curr = max(nums[i]+nums[i-2], curr);

            nums[i] = curr;
        }

        for (int i: nums) maxAmount = max(maxAmount, i);

        return maxAmount;
    }
};