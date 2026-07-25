class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> freq;
            multiset<int> st;

            for (int j = i; j < s.size(); j++) {

                if (freq[s[j]] > 0) {
                    auto it = st.find(freq[s[j]]);
                    st.erase(it);
                }

                freq[s[j]]++;
                st.insert(freq[s[j]]);

                int minFreq = *st.begin();
                int maxFreq = *st.rbegin();

                ans += maxFreq - minFreq;
            }
        }

        return ans;
    }
};