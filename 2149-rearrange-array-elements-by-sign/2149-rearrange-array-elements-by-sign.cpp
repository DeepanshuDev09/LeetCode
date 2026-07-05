class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int x = 0;
        int y = 1;
        
        for (int i: nums){
            if (i < 0){
                result[y] = i;
                y = y + 2;
            }
            else {
                result[x] = i;
                x = x + 2;
            }
        }

        return result;
    }
};