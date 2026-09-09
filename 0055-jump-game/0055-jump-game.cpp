class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0];

        for (int i = 0; i<n; i++){
            if (i <= curr){
                curr = max(i + nums[i], curr);
            }
            else {
                return false;
            }
        }

        return true;
    }
};