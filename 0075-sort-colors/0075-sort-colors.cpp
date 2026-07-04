class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int curr = 0;
        int j = nums.size() - 1;

        while (curr <= j){
            if (nums[curr] == 0){
                swap(nums[curr], nums[i]);
                i++;
                curr++;
            }
            else if (nums[curr] == 2){
                swap(nums[curr], nums[j]);
                j--;
            }
            else {
                curr++;
            }
        }
    }
};