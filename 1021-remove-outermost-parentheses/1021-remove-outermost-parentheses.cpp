class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;

        for (int i = 0; i<s.size(); i++){
            if (s[i] == '('){
                int count = 1;
                i++;

                while (count > 0){
                    if (s[i] == '('){
                        count++;
                        if (count > 1) ans.push_back('(');
                    }
                    else {
                        count--;
                        if (count > 0) ans.push_back(')');
                    }
                    i++;
                }
                i--;
            }
        }

        return ans;
    }
};