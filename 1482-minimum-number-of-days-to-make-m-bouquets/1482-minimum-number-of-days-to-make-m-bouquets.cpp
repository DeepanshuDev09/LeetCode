class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL * m * k > bloomDay.size()) return -1;
        int min = INT_MAX;
        int max = INT_MIN;

        for (int i: bloomDay){
            if (max < i) max = i;
            if (min > i) min = i;
        }

        if (m * k == bloomDay.size()) return max;
        int ans = max;

        while (min <= max){
            int mid = min + (max-min)/2;
            int flowerCount = 0;
            int bouquetCount = 0;

            for (int i = 0; i<bloomDay.size(); i++){
                if (bloomDay[i] <= mid) { flowerCount++; }
                else { flowerCount = 0; }
                if (flowerCount == k) {
                    flowerCount = 0;
                    bouquetCount++;
                }
            }

            if (bouquetCount >= m){
                ans = mid;
                max = mid - 1;
            }
            else { min = mid + 1; } 
        }

        return ans;
    }
};