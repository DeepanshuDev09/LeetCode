class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixMax;
        vector<int> suffixMin;

        for (int i = 0; i<n; i++){

            if (prefixMax.empty() || prefixMax.back() < nums[i]){
                prefixMax.push_back(nums[i]);
            }
            else {
                prefixMax.push_back(prefixMax.back());
            }

            if (suffixMin.empty() || suffixMin.back() > nums[n - i - 1]){
                suffixMin.push_back(nums[n - i - 1]);
            }
            else {
                suffixMin.push_back(suffixMin.back());
            }
        }

        for (int i = 0; i<n; i++){
            int curr = prefixMax[i] - suffixMin[n - i - 1];
            if (curr <= k) return i;
        }

        return -1;
    }
};