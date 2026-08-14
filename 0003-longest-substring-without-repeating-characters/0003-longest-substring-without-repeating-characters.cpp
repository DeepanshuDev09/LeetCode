class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set;
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right<s.size(); right++){
            while (left <= right && set.find(s[right]) != set.end()){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            maxLen = max(maxLen, (int)set.size());
        }

        return maxLen;
    }
};