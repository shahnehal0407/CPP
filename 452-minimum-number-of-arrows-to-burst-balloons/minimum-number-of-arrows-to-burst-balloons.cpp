class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>>store;
        for(int i=0;i<points.size();i++){
            store.push_back({points[i][1],points[i][0]});
        }

        sort(store.begin(),store.end());
        int pos=store[0].first;
        int count=1;

        for(int i=1;i<store.size();i++){
            if(store[i].second>pos){count++;
            pos=store[i].first;

            }
        }
    return count;
    }
};