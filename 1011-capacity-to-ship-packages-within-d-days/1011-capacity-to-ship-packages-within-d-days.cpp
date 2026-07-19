class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
        int high = 0;

        for (int i: weights){
            high += i;
            if (low < i) low = i;
        }

        int ans = high;

        while (low <= high){
            int mid = low + (high-low)/2;
            int currDays = 1;
            int load = 0;

            for (int i: weights){
                if (load + i > mid){
                    currDays++;
                    load = i;
                }
                else { load += i; }
            }

            if (currDays <= days){
                ans = mid;
                high = mid - 1;
            }
            else { low = mid + 1; }
        }

        return ans;
    }
};