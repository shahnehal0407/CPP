class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>store;
        store.push_back(meetings[0]);
        int first;
        int second;
        for(int i=1;i<meetings.size();i++){
            first=meetings[i][0];
            second=meetings[i][1];

            if(!store.empty() && second<=store.back()[1])continue;
            else if(!store.empty() && first<=store.back()[1])store.back()[1]=second;
            else store.push_back(meetings[i]);
        }


        int count=0;
        for(int i=0;i<store.size();i++){
            count+=(store[i][1]-store[i][0]+1);
        }

        return days-count;
    }
};