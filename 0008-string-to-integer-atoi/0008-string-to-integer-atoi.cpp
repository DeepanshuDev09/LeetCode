class Solution {
public:
    int myAtoi(string input) {
        int sign = 1;
        long long ans = 0;
        int i = 0;

        while (i < input.size() && input[i] == ' ') i++;

        if (input[i] == '+') {
            sign = 1; 
            i++;
        }
        else if (input[i] == '-'){ 
            sign = -1;
            i++;
        }

        while (i < input.size() && isdigit(input[i])) {
            ans = ans * 10 + (input[i] - '0');
            if (sign == 1 && ans > INT_MAX)
                return INT_MAX;

            if (sign == -1 && -ans < INT_MIN)
                return INT_MIN;
            i++;
        }

        return sign * ans;
    }
};
