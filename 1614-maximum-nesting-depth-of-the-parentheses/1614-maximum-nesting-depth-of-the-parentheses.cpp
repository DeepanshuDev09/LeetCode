class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int result = 0;

        for (char i: s){
            if (i == '('){
                count++;
                result = max(result, count);
            }
            if (i == ')') count--;
        }

        return result;
    }
};