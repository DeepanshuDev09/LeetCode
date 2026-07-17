class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int n = nums.size() - 1;
        int st = 0, end = n;

        while (st <= end){
            int mid = st + (end-st)/2;
            if (mid == 0 && nums[mid+1] < nums[mid]) { return mid; break; }
            if (mid == n && nums[mid-1] < nums[mid]) { return mid; break; }

            if (nums[mid] < nums[mid+1]){
                st = mid + 1;
            }
            else if (nums[mid] < nums[mid-1]){
                end = mid - 1;
            }
            else {
                return mid;
            }
        }

        return 0;
    }
};