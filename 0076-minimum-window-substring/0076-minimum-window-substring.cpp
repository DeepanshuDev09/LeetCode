class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> charCount;
        for (char ch : t) {
            charCount[ch]++;
        }

        int CharsRemaining = t.size();
        int minWindow[2] = {0, INT_MAX};
        int left = 0;

        for (int right = 0; right<s.size(); right++) {
            char ch = s[right];
            if (charCount.find(ch) != charCount.end() && charCount[ch] > 0) {
                CharsRemaining--;
            }
            charCount[ch]--;

            if (CharsRemaining == 0) {
                while (true) {
                    char charAtStart = s[left];
                    if (charCount.find(charAtStart) != charCount.end() && charCount[charAtStart] == 0) {
                        break;
                    }
                    charCount[charAtStart]++;
                    left++;
                }

                if (right - left < minWindow[1] - minWindow[0]) {
                    minWindow[0] = left;
                    minWindow[1] = right;
                }

                charCount[s[left]]++;
                CharsRemaining++;
                left++;
            }
        }

        return minWindow[1] >= s.size() ? "" : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);        
    }
};