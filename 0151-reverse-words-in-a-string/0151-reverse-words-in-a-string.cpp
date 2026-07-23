class Solution {
public:
    string reverseWords(string s) {
        int n = s.size() - 1;
        string ans;

        while (n >= 0){
            if (s[n] != ' '){
                int end = n;

                while (n >= 0 && s[n] != ' ') n--;
                int st = n+1;

                if (!ans.empty()) ans.push_back(' ');

                for (int i = st; i<=end; i++) ans.push_back(s[i]);
            }
            else {
                n--;
            }
        }

        return ans;
    }
};