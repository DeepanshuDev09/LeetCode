class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i<asteroids.size(); i++){
            if (asteroids[i] < 0){
                while (true){
                    if (st.empty() || st.top() < 0){
                        st.push(asteroids[i]);
                        break;
                    }
                    if (st.top() == -(asteroids[i])){
                        st.pop();
                        break;
                    }
                    else if (st.top() < -(asteroids[i])) {
                        st.pop();
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                st.push(asteroids[i]);
            }
        }

        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};