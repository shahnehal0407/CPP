class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        vector<int>prev(n);
        vector<int>next(n);
        const int MOD = 1e9 + 7;
        stack<int>s;

        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i])s.pop();
            prev[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
            next[i]=s.empty()? n : s.top();
            s.push(i);
        }
        
        vector<int>prev1(n);
        vector<int>next1(n);
 
        while(!s.empty())s.pop();

        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]<arr[i])s.pop();
            prev1[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]<=arr[i])s.pop();
            next1[i]=s.empty()? n : s.top();
            s.push(i);
        }
        

        long long minSum = 0, maxSum = 0;
        for (int i = 0; i < n; i++) {
            long long leftMin = i - prev[i];
            long long rightMin = next[i] - i;
            minSum += arr[i] * leftMin * rightMin;

            long long leftMax = i - prev1[i];
            long long rightMax = next1[i] - i;
            maxSum += arr[i] * leftMax * rightMax;
        }

        return maxSum - minSum;
    }
};