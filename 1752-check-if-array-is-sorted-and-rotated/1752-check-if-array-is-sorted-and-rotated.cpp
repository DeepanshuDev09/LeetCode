class Solution {
public:
    bool check(vector<int>& nums) {
        int check = 0;
        int i = 1;
        while (i<nums.size()){
            if (nums[i] >= nums[i-1]){
                i++;
                continue;
            }
            else if (nums[i] > nums[0]){
                return 0;
            }
            else {
                 i++;
                while (i<nums.size()){
                    if (nums[i] <= nums[0] && nums[i] >= nums[i-1]){
                        i++;
                        continue;
                    }
                    else {
                        return 0;
                    }
                }
            }
        }

        return 1;
    }
};