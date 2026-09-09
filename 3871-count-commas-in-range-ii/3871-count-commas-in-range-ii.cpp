class Solution {
public:
    long long countCommas(long long n) {
        long long count = max(n - 999LL, 0LL);
        long long curr = 999999;

        while (n > curr){
            count += max(n - curr, 0LL);
            curr++;
            curr = curr * 1000;
            curr--;
        }


        return count;
    }
};