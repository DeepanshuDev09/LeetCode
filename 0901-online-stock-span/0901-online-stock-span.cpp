class StockSpanner {
    vector<int> prev;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        prev.push_back(price);
        int count = 0;

        for (int i = prev.size()-1; i>=0; i--){
            if (prev[i] > price) break;
            count++;
        }

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */