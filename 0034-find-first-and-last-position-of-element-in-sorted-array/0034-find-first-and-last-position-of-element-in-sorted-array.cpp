class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};
        int stIndex = -1, endIndex = -1;
        int st = 0;
        int end = nums.size() - 1;
        int midSt, midEnd;

        while (st <= end){
            midSt = st + (end-st)/2;

            if (nums[midSt] < target){
                st = midSt + 1;
            }
            else if (nums[midSt] > target){
                end = midSt - 1;
            }
            else {
                if (midSt == 0){
                    break;
                }
                else if (nums[midSt-1] == target) {
                    end = midSt - 1;
                }
                else { break; }
            }
        }

        if (nums[midSt] != target) return {-1, -1};
        st = 0;
        end = nums.size() - 1;

        while (st <= end){
            midEnd = st + (end-st)/2;

            if (nums[midEnd] < target){
                st = midEnd + 1;
            }
            else if (nums[midEnd] > target){
                end = midEnd - 1;
            }
            else {
                if (midEnd == nums.size() - 1){
                    break;
                }
                else if (nums[midEnd+1] == target) {
                    st = midEnd + 1;
                }
                else { break; }
            }
        }

        return {midSt, midEnd};
    }
};