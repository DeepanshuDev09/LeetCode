class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp;

        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int ans = 0;
        int count = 0;

        while (count < s.size()-1){
            char curr = s[count];
            char next = s[count+1];

            if (mpp[next] > mpp[curr]){
                ans += mpp[next] - mpp[curr];
                count += 2;
                continue;
            }

            ans += mpp[curr];
            count++;
        }

        if (count < s.size()){
            char curr = s[count];
            ans += mpp[curr];
            count++;
        }

        return ans;  
    }
};