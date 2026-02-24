class MyCalendarTwo {
public:
vector<pair<int,int>>booking;
vector<pair<int,int>>overlap;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<overlap.size();i++){
            int s=overlap[i].first;
            int e=overlap[i].second;
            if(s<end && start<e)return false;
        }
        for(int i=0;i<booking.size();i++){
            int s=booking[i].first;
            int e=booking[i].second;
            if(s<end && start<e)overlap.push_back({max(s,start),min(e,end)});

        }
       
         booking.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */