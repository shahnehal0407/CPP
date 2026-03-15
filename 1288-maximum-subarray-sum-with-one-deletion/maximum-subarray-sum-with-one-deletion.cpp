class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int noDeletion = arr[0];
        int oneDeletion = 0;
        int ans = arr[0];

        for(int i = 1; i < arr.size(); i++){

            oneDeletion = max(noDeletion, oneDeletion + arr[i]);

            noDeletion = max(arr[i], noDeletion + arr[i]);

            ans = max(ans, max(noDeletion, oneDeletion));
        }

        return ans;
    }
};