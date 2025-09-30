class MedianFinder {
public:
    priority_queue<int> maxHeap; // left half (smaller numbers)
    priority_queue<int, vector<int>, greater<int>> minHeap; // right half (larger numbers)

    MedianFinder() {}

    void addNum(int num) {
        // Step 1: always push into maxHeap first
        maxHeap.push(num);

        // Step 2: fix order -> largest of left <= smallest of right
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: fix size -> maxHeap can have one extra element
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top(); // odd length
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0; // even length
        }
    }
};
