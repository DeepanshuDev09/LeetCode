class MinStack {
    stack<int> st;
    stack<int> sortedSt;
public:
    MinStack() {
    }

    void push(int value) {
        st.push(value); 
        if (sortedSt.empty()) {
            sortedSt.push(value);
        }
        else {
            sortedSt.push(min(value, sortedSt.top()));
        }
    }
    
    void pop() {
        sortedSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();  
    }
    
    int getMin() {
        return sortedSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */