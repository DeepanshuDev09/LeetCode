class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, 0);
        int count = 0;
        int lastCount = 0;
        int left = 0;

        for (int right = 0; right<s.size(); right++){
            freq[s[right] - 'a']++;
            int curr = 0;

            while (freq[0] >= 1 && freq[1] >= 1 && freq[2] >= 1){
                curr += 1;
                freq[s[left] - 'a']--;
                left++;
            }

            count += lastCount + curr;
            lastCount = lastCount + curr;
        }

        return count;
    }
};