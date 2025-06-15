class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        stack<int>s;
        int ans =0;
        for(int i=0;i<=n;i++){
            int ch= (i==n) ? 0 :h[i];
            while(!s.empty() && h[s.top()]>ch){
                int hi= h[s.top()];
                s.pop();

                int wi= s.empty()?i:i-s.top()-1;


                ans = max(ans,hi*wi);
            }
                s.push(i);
        }




   return ans;

    }
};