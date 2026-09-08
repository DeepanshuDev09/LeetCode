class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int countFive = 0, countTen = 0, countTwenty = 0;

        for (int i: bills){
            if (i == 5){
                countFive++;
            }
            else if (i == 10){
                if (countFive == 0) return false;
                countFive--;
                countTen++;
            }
            else {
                if (countFive == 0) return false;
                if (countTen == 0){
                    if (countFive < 3) return false;
                    countFive -= 3;
                }
                else {
                    countFive--;
                    countTen--;
                }

                countTwenty++;
            }
        }

        return true;
    }
};