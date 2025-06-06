class MinStack {
public:
    int m=INT_MAX;
    queue<int>q;

    void push(int val) {
        m=min(m,val);
        q.push(val);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    

    void pop() {
        int e=q.front();
        q.pop();
        if(m==e){
            m=INT_MAX;
            for(int i=0;i<q.size();i++){
                m=min(m,q.front());
                q.push(q.front());
                q.pop();
            }
            
     }

    }
    
    int top() {
        return q.front();
    }
    
    int getMin() {
        return m;

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */