class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size() - 1;
        int trim = -1;
        string ans;

        for (int i = n; i>=0; i--){
            int x = num[i] - '0';
            if (x%2 != 0){
                trim = i;
                break;
            }
        }

        if (trim < 0) return "";

        for (int i = 0; i<=trim; i++){
            ans.push_back(num[i]);
        }

        return ans;
    }
};