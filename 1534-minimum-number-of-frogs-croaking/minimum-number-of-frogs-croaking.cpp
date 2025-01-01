class Solution {
public:
    int minNumberOfFrogs(string frog) {
       int onGoing = 0;
        int maxOngoing = 0;
        vector<int> dp(5, 0);
        for(auto a : frog){
            if(a == 'c'){
                dp[0]++;
                onGoing++;
                maxOngoing = max(maxOngoing, onGoing);
            }else{
                if(a == 'r'){
                    if(dp[0] <= dp[1]) return -1;
                    dp[1]++;
                }else if(a == 'o'){
                    if(dp[1] <= dp[2]) return -1;
                    dp[2]++;
                }else if(a == 'a'){
                    if(dp[2] <= dp[3]) return -1;
                    dp[3]++;
                }else if(a == 'k'){
                    if(dp[3] <= dp[4]) return -1;
                    dp[4]++;
                    onGoing--;
                }
            }
        }
        int total = dp[0];
        for(int i = 1; i < 5; i++){
            if(dp[i] != total) return -1;
        }
        
        return maxOngoing;
    }
};