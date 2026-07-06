class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int prefix = -1;
        int n = nums.size() - 1;
        
        for (int i = n; i>0; i--){
            if (nums[i] > nums[i-1]){
                prefix = i;
                break;
            }
        }

        if (prefix == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n; i>=prefix; i--){
            if (nums[prefix-1] < nums[i]){
                swap(nums[prefix-1], nums[i]);
                break;
            }
        }

        reverse(nums.begin() + prefix, nums.end());
    }
};