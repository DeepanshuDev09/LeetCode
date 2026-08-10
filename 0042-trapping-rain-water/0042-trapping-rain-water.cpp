class Solution {
public:
    int trap(vector<int>& nums) {
        int ans = 0;
        int rightMax = nums.size() - 1;
        int leftMax = 0;
        int i = 0, j = nums.size() - 1;

        while (i < j){
            if (nums[leftMax] <= nums[rightMax]){
                i++;
                if (i == j) return ans;
                if (nums[leftMax] <= nums[i]){
                    leftMax = i;
                }
                else {
                    ans += nums[leftMax] - nums[i];
                }
            }
            else {
                j--;
                if (i == j) return ans;
                if (nums[rightMax] <= nums[j]){
                    rightMax = j;
                }
                else {
                    ans += nums[rightMax] - nums[j];
                }
            }
        }

        return ans;
    }
};