class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int st = 1;
        int end = 0;

        for (int i: nums){
            if (end < i) end = i;
        }

        int ans = end;

        while (st <= end){
            int mid = st + (end-st)/2;
            int currH = 0;

            for (int i = 0; i<nums.size(); i++){
                currH += (nums[i] + mid - 1)/mid;
                if (currH > h) break;
            }

            if (currH <= h){
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return ans;
    }
};