class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        stk.push(x);
        if (minStk.empty()) {
            minStk.push(x);
        }
        else {
            if (x <= minStk.top()) {
                minStk.push(x);
            }
        }
    }

    void pop() {
        if (stk.top() == minStk.top()) {
            minStk.pop();
        }
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }

private:
    stack<int> stk;
    stack<int> minStk;
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */