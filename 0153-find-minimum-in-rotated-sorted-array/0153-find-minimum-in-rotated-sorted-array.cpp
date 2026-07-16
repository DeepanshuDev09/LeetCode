class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = INT_MAX;
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end){
            int mid = st + (end-st)/2;

            if (nums[mid] <= nums[end]){
                result = min(result, nums[mid]);
                end = mid - 1;
            }
            else {
                result = min(result, nums[st]);
                st = mid + 1;
            }
        }

        return result;
    }
};