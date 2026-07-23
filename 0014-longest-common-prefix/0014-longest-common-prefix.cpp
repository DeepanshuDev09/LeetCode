class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;

        for (int i = 0; i<strs[0].size(); i++){
            char curr = strs[0][i];

            for (int j = 1; j<strs.size(); j++){
                if (strs[j][i] != curr) return ans;
            }

            ans.push_back(curr);
        }

        return ans;
    }
};