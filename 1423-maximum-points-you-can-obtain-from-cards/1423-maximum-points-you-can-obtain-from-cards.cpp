class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0;
        int left = 0;
        int sum = 0;

        for (int right = n-k; right<n; right++){
            sum += cardPoints[right];
            ans = max(sum, ans);
        }

        int i = 0;
        while (k > 0){
            sum -= cardPoints[n-k];
            sum += cardPoints[i];
            i++; k--;
            ans = max(ans, sum);
        }

        return ans;
    }
};