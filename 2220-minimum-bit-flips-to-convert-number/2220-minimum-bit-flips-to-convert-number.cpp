class Solution {
    string decimalToBinary(int n){
        string binary = "";
        while (n > 0){
            int curr = n % 2;
            binary.push_back( (curr + '0') );
            n = n/2;
        }
        reverse(binary.begin(), binary.end());

        return binary;
    }
public:
    int minBitFlips(int start, int goal) {
        int bothXOR = goal ^ start;
        string binaryXOR = decimalToBinary(bothXOR); 
        int steps = 0;  

        for (int i = 0; i<binaryXOR.size(); i++){
            if (binaryXOR[i] == '1') steps++;
        }

        return steps;
    }
};