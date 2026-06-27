class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j){
            while (i < j && !(isalnum(static_cast<unsigned char>(s[i])))) i++;
            while (i < j && !(isalnum(static_cast<unsigned char>(s[j])))) j--;

            if (tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            }
            else {
                return 0;
            }
        }

        return 1;
    }
};