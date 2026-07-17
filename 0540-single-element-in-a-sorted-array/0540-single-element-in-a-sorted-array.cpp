class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        while (st < end){
            int mid = st + (end-st)/2;

            if (mid%2 == 0){
                if (nums[mid] == nums[mid+1]){
                    st = mid + 2;
                }
                else if (nums[mid] == nums[mid-1]){
                    end = mid - 2;
                }
                else {
                    return nums[mid];
                }
            }

            else {
                if (nums[mid] == nums[mid+1]){
                    end = mid - 1;
                }
                else if (nums[mid] == nums[mid-1]){
                    st = mid + 1;
                }
                else {
                    return nums[mid];
                }
            }
        }

        return nums[st];
    }
};