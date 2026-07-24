class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        int n = s.size();

        for (int shift = 0; shift < n; shift++) {
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (s[i] != goal[(i + shift) % n]) {
                    ok = false;
                    break;
                }
            }

            if (ok) return true;
        }

        return false;
    }
};