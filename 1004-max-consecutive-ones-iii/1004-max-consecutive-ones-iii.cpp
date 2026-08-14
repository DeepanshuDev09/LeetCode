class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> lastZero;
        int left = 0;
        int ans = 0;

        for (int right = 0; right<nums.size(); right++){
            if (nums[right] == 0){
                lastZero.push(right);
                k--;
            }

            if (k < 0){
                left = lastZero.front();
                k++; left++;
                lastZero.pop();
            }

            int currSize = right - left + 1;
            ans = max(currSize, ans);

        }

        return ans; 
    }
};