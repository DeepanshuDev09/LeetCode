class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> numsHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            numsHeap.push(num);

            if (numsHeap.size() > k) {
                numsHeap.pop();
            }
        }
    }
    
    int add(int val) {
        numsHeap.push(val);

        if (numsHeap.size() > k) {
            numsHeap.pop();
        }

        return numsHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */