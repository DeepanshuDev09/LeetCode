class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        int totalGroups = n / groupSize;
        vector<priority_queue<int>> groups(totalGroups);
        int emptyGroupIndex = 0;

        sort(hand.begin(), hand.end());
        
        for (int i = 0; i<n; i++){
            int curr = hand[i];

            for (int j = 0; j<groups.size(); j++){

                if (!groups[j].empty() && groups[j].size() < groupSize && curr - 1 == groups[j].top()){
                    groups[j].push(curr);
                    break;
                }

                if (j == groups.size() - 1){
                    if (emptyGroupIndex < totalGroups){
                        groups[emptyGroupIndex].push(curr);
                        emptyGroupIndex++;
                    }
                    else { return false; }
                }
            }
        }

        return true;
    }
};