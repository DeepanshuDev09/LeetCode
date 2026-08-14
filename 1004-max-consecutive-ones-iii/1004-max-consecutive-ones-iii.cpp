class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lastZero = -1;
        int left = 0;
        int ans = 0;

        for (int right = 0; right<nums.size(); right++){
            if (nums[right] == 0) k--;

            if (k < 0){
                while (left <= right && nums[left] != 0) left++;
                left++; k++;
            }

            int currSize = right - left + 1;
            ans = max(currSize, ans);

        }

        return ans;
    }
};