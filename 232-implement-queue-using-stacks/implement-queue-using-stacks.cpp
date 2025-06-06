class MyQueue {
public:
    stack<int>s1,s2;
    
  void push(int x) {
        // Push to s1 directly — no swapping needed
        s1.push(x);
    }

    int pop() {
        // If s2 is empty, refill it from s1 (reverses the order)
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int e = s2.top();
        s2.pop();
        return e;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */