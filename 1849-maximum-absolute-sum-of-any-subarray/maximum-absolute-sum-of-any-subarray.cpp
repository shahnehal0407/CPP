class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int mincur=0, maxcur=0;
        int ansmin=0, ansmax=0;
        for(int i=0;i<arr.size();i++){
            mincur=min(arr[i],mincur+arr[i]);
            ansmin=min(ansmin,mincur);

            maxcur=max(arr[i],maxcur+arr[i]);
            ansmax=max(ansmax,maxcur);
        } 

        return max(abs(ansmin), abs(ansmax));
    }
};