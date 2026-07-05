class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int even = 0;
        int odd = 1;

        for (int i: nums){
            if (i > 0){
                result[even] = i;
                even += 2;
            }
            else {
                result[odd] = i;
                odd += 2;
            }
        }

        return result;
    }
};