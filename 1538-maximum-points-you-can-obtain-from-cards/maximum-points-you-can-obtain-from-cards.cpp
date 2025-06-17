// class Solution {
// public:
//     int maxScore(vector<int>& c, int k) {
//         int i=0;
//         int j=c.size()-1;
//         int ans=0;

//         while(i<=j && k>0){
//          ans+= max(c[i],c[j]);
//          if(c[i]>c[j])i++;
//          else j--;
//          k--;
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int total=0;
        int ans=0;
        int n=c.size();
        for(int i=0;i<k;i++){
            total+=c[i];
        }
        ans =total;

        for(int i=0;i<k;i++){
            total -=c[k-i-1];
            total +=c[n-i-1];
            ans =max(ans,total);
        }
        return ans;
    }
};