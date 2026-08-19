class Solution {
    int solve(vector<int>& nums, int k){
        int count = 0;
        int left = 0, right = 0;
        unordered_map<int, int> mpp;
        
        while (right < nums.size()){
            mpp[nums[right]]++;

            while (mpp.size() > k){
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left = left + 1;
            }

            count = count + (right - left + 1);
            right = right + 1;
        }

        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};