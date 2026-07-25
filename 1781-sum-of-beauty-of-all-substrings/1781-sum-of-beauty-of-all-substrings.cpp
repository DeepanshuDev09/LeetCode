class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            vector<int> count(26);

            for (int j = i; j < s.size(); j++) {
                int curr = s[j] - 'a';
                count[curr]++;

                int minFreq = INT_MAX;
                int maxFreq = INT_MIN;
                for (int i: count){
                    if (i != 0) minFreq = min(minFreq, i);
                    maxFreq = max(maxFreq, i);
                }
                if (minFreq == INT_MAX) continue;
                ans += (maxFreq - minFreq);
            }
        }

        return ans;
    }
};