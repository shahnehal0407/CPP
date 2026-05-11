class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int val=INT_MAX;
        int ans=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<val)val=prices[i];
            else if(prices[i]-val>ans)ans=prices[i]-val;
        }
        return ans;
    }
};