class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int, int> mpp;
        mpp[0] = 1;

        int oddCount = 0;
        int ans = 0;

        for (int i: nums){
            if (i % 2 == 1) oddCount++;

            ans += mpp[oddCount - k];

            mpp[oddCount]++;
        }

        return ans;
    }
};