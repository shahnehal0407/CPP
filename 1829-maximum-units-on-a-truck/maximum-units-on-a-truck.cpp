class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int truckSize) {
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
             return a[1] >b[1]; 
                });

            int ans=0;
                for(int i=0;i<arr.size();i++){
                    if(truckSize>=arr[i][0]){
                        ans +=arr[i][0]*arr[i][1];
                        truckSize-=arr[i][0];
                    }
                    else {ans+=arr[i][1]*truckSize;
                    break;}
                }
                return ans;
    }
};