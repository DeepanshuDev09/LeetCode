class Solution {
    void checkPrime(vector<int>& nums, int curr, int n){
        if (curr >= nums.size()) return;

        int num = curr + 2;

        if (nums[curr] != 0){
            for (int i = 2 * num; i < n; i += num) nums[i - 2] = 0;
        }

        checkPrime(nums, curr+1, n);
    }

public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> nums;

        for (int i = 2; i<n; i++) nums.push_back(1);

        checkPrime(nums, 0, n);

        for (int i: nums){
            if (i == 1) count++;
        }

        return count;
    }
};