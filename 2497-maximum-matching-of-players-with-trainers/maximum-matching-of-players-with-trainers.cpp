class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int i=0;
        int j=0;
        int ans=0;
        while(i<=j && j<trainers.size() && i<players.size()){
            if(players[i]<=trainers[j]){ans++;i++;}
            j++;

        }
        return ans;
    }
};