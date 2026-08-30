class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = 0, maxIndex = 0;
        int ans = INT_MAX;

        for (int i = 0; i<n; i++){
            if (nums[i] < nums[minIndex]) minIndex = i;
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }

        if (minIndex > maxIndex){
            ans = min(minIndex+1, ans);
            ans = min(n - maxIndex, ans);
            int curr = n - minIndex + maxIndex+1;
            ans = min(curr, ans);
        }
        else {
            ans = min(maxIndex+1, ans);
            ans = min(n - minIndex, ans);
            int curr = n - maxIndex + minIndex+1;
            ans = min(curr, ans);
        }

        return ans;

        // if (n/2 <= minIndex && n/2 <= maxIndex){
        //     if (minIndex > maxIndex){
        //         return n - minIndex;
        //     }
        //     return n - maxIndex;
        // }
        // else if (n/2 >= minIndex && n/2 >= maxIndex){
        //     if (minIndex > maxIndex){
        //         return minIndex;
        //     }
        //     return maxIndex;
        // }
        // else if ((n/4 - n/2) <= minIndex && (n/4 + n/2) >= maxIndex){
        //     return maxIndex;
        // }
        // else if ((n/4 + n/2) >= minIndex && (n/4 - n/2) >= maxIndex){
        //     return n - 
        // }
    }
};