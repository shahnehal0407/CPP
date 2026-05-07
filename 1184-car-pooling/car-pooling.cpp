class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>>start;
        vector<pair<int,int>>end;
        for(int i=0;i<trips.size();i++){
            start.push_back({trips[i][1],trips[i][0]});
            end.push_back({trips[i][2],trips[i][0]});
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
    int i=0;
    int j=0;
    int cur=0;
        while(i<start.size()){
            while(j<end.size() && end[j].first<=start[i].first){
                cur-=end[j].second;
                j++;
            }

            cur+=start[i].second;
            

            if(cur>capacity)return false;
            i++;
        }


        return true;
    }
};