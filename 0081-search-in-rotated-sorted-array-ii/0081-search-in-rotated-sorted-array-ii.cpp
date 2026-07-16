class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int st = 0;
        int end = nums.size() - 1;
        while (st <= end){
            int mid = st + (end-st)/2;
            if (nums[mid] < target){
                st = mid + 1;
            }
            else if (nums[mid] > target){
                end = mid - 1;
            }
            else {
                return 1;
            }
        }
        return 0;
    }
};