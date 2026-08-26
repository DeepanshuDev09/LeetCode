class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int minLen = INT_MAX;
        int minIndex = 0;
        int count = 0, left = 0;
        string ans;

        for (int right = 0; right<s.size(); right++){
            if (s[right] == '1') count++;

            while (count == k){
                if (count == k){
                    int len = right - left + 1;
                    if (minLen > len){
                        minLen = right - left + 1;
                        ans = s.substr(left, len);
                    }
                    if (minLen == len){
                        if (s.substr(left, len) < ans) ans = s.substr(left, len);
                    }
                }

                if (s[left] == '1') count--;
                left++;
            }

        }

        if (minLen == INT_MAX) return "";

        return ans;
    }
};