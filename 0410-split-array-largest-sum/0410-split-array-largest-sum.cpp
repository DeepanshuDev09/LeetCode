class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN;
        int high = 0;

        for (int i: nums){
            high += i;
            if (low < i) low = i;
        }
        int ans = high;

        while (low <= high){
            int mid = low + (high-low)/2;
            int count = 1;
            int currSum = 0;

            for (int i: nums){
                currSum += i;
                if (currSum > mid){
                    currSum = i;
                    count++;
                }
            }

            if (count <= k){
                ans = mid;
                high = mid - 1;
            }
            else { low = mid + 1; }
        }

        return ans;
    }
};