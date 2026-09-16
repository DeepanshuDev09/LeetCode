class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int lastJump = 0;
        vector<int> minJump(n, INT_MAX);
        minJump[0] = 0;

        for (int i = 0; i<n; i++){
            for (int j = i + 1; j <= min(n - 1, i + nums[i]); j++) {
                minJump[j] = min(minJump[j], minJump[i] + 1);
            }
        }

        return minJump[n-1];
    }
};