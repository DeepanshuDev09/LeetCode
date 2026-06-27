class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return 0;
        if (x < 10) return 1;

        int num = x;
        double rev = 0;

        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        if (rev == num) return 1;

        return 0;
    }
};