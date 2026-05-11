class MyCircularDeque {
public:
    vector<int>store;
    int front;
    int rear;
    int size;
    int capacity;
    MyCircularDeque(int k) {
        store.resize(k);
        capacity=k;
        size=0;
        front=0;
        rear=k-1;

    }
    
    bool insertFront(int value) {
        if(isFull())return false;
        front=(front+capacity-1)%capacity;
        store[front]=value;
        size++;
        return true;

    }
    
    bool insertLast(int value) {
         if(isFull())return false;
         rear=(rear+1)%capacity;
         store[rear]=value;
         size++;
        return true;

    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        front=(front+1)%capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }
    
    int getFront() {
          if(isEmpty())return -1;
          else return store[front];
    }
    
    int getRear() {
        if(isEmpty())return -1;
          else return store[rear];
    }
    
    bool isEmpty() {
        if(size==0)return true;
        else return false;
    }
    
    bool isFull() {
        if(size==capacity)return true;
        else return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */