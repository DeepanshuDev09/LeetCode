class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int st = 0;
        int end = nums.size() - 1;
        int ans = end + 1 + k;

        while (st <= end){
            int mid = st + (end-st)/2;

            int currMissing = nums[mid] - 1 - mid;

            if (currMissing >= k){
                ans = k + mid;
                end = mid - 1;
            }
            else { st = mid + 1; }
        }

        return ans;
    }
};