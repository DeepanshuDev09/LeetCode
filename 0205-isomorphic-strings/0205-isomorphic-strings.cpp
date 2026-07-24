class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> mpp;
        unordered_map<char, char> mpp2;

        for (int i = 0; i<s.size(); i++){
            char curr = s[i];
            char curr2 = t[i];

            if (mpp[curr] == 0 || mpp[curr] == t[i]){
                mpp[curr] = t[i];
            }
            else { return false; }

            if (mpp2[curr2] == 0 || mpp2[curr2] == s[i]){
                mpp2[curr2] = s[i];
            }
            else { return false; }
        }

        return true;
    }
};