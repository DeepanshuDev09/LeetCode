class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int st = 1;
        int end = INT_MIN;

        for (int i: nums) if (end < i) end = i;
        int ans = end;

        while (st <= end){
            int mid = st + (end-st)/2;
            int sum = 0;

            for (int i: nums) sum += (i + mid - 1)/mid;

            if (sum > threshold){
                st = mid + 1;
            }
            else {
                ans = mid;
                end = mid - 1;
            }
        }

        return ans;
    }
};