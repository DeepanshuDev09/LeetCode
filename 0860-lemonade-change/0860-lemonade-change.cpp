class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> changeInHand;

        for (int i = 0; i<bills.size(); i++){
            if (bills[i] > 5){
                int n = changeInHand.size() - 1;
                int need = bills[i] - 5;
                sort(changeInHand.begin(), changeInHand.end());

                while (n >= 0 && need != 0){
                    if (changeInHand[n] <= need){
                        need -= changeInHand[n];
                        changeInHand[n] = 0;
                    }
                    
                    n--;
                }

                if (n < 0 && need != 0) return false;
            }
            
            changeInHand.push_back(bills[i]);
        }

        return true;
    }
};