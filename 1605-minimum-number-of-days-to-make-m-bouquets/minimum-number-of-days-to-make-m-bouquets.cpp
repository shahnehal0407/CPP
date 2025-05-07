class Solution {
public:

    bool helper(const vector<int>& a, int day, int m, int k){
        int count=0;
        int bouquet=0;
         for(int i=0;i<a.size(); i++){
            if(a[i]<=day) {
                count++;
             if(count==k){
                bouquet++;
                count =0;
                }}
            else count =0;
    }
    return bouquet >= m;
    }

    int minDays(vector<int>& a, int m, int k) {
        int n=a.size();
        int output=0;
        long long total = 1LL * m * k;
    if (n < total) return -1;
         
         int  min =*min_element(a.begin(),a.end());
         int  max = *max_element(a.begin(),a.end());

         while (min<=max){
         int day = (max+min)/2;
         if(helper(a,day,m,k)) {
            output=day;
            max = day-1;
         }
         else{
         min = day+1;
         }
         }
      return output;

    }

};