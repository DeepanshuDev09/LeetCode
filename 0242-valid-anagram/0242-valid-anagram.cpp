class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> check(26);

        for (int i = 0; i<s.size(); i++){
            char curr = s[i];
            int place = curr - 'a';
            check[place]++;

            char curr2 = t[i];
            int place2 = curr2 - 'a';
            check[place2]--;
        }

        for (int i = 0; i<check.size(); i++){
            if (check[i] != 0) return false;
        }

        return true;
    }
};