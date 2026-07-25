class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int ansLow = 0, ansHigh = 0;
        string ans;

        for (int i = 0; i<s.size(); i++){
            
            int low = i, high = i;
            while (low >= 0 && high < s.size() && s[low] == s[high]) {
                if (high - low + 1 > maxLen) {
                    maxLen = high - low + 1;
                    ansLow = low;
                    ansHigh = high;
                }
                low--;
                high++;
            }

            low = i;
            high = i + 1;
            while (low >= 0 && high < s.size() && s[low] == s[high]) {
                if (high - low + 1 > maxLen) {
                    maxLen = high - low + 1;
                    ansLow = low;
                    ansHigh = high;
                }
                low--;
                high++;
            }
        }

        for (int i = ansLow; i<= ansHigh; i++) ans.push_back(s[i]);

        return ans;
    }
};