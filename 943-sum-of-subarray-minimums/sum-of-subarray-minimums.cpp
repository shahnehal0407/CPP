
// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int m;
//         long int sum=0;


//         for(int i=0;i<arr.size();i++){
//             m=arr[i];
//             for(int j=i;j<arr.size();j++){
//                  m=min(m,arr[j]);
//                  sum +=m;

//             }
//         }
//         return sum;
//     }
// };
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
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
        
        long ans=0;
        for(int i=0;i<n;i++){
            long left = i-prev[i];
            long right = next[i]-i;
            ans = (ans+((left%MOD)*(right%MOD)*arr[i]))%MOD;
        }

        return (int)ans;
    }
};