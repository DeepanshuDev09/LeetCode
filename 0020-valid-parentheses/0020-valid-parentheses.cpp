class Solution {
public:
    bool isValid(string s) {
        vector<char> open = {'(','{','['};
        vector<char> close = {')','}',']'};
        stack<char> st;

        for (int i = 0; i<s.size(); i++){
            int index = -1;
        
            for (int j = 0; j<close.size(); j++){
                if (s[i] == close[j]) index = j;
            }

            if (st.empty() && index >= 0) return false;

            if (index >= 0 && st.top() != open[index]) return false;

            if (index >= 0 && st.top() == open[index]) st.pop();

            if (index < 0) st.push(s[i]);
        }

        if (!st.empty()) return false;

        return true;
    }
};