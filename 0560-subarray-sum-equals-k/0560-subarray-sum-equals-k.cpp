class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0, count = 0;
        map<int, int> mpp;
        mpp[0]++;;

        for (int i = 0; i<nums.size(); i++){
            prefixSum += nums[i];
            int check = prefixSum - k;
            count += mpp[check];
            mpp[prefixSum]++;
        }

        return count;
    }
};