class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
    
            long long sum1=0;
            long long sum2=0;
            int count1=0;
            int count2=0;
            for(int i=0;i<nums1.size();i++){
                sum1+=max(nums1[i],1);
                if(nums1[i]==0)count1++;
            
            }
            for(int j=0;j<nums2.size();j++){
                sum2+=max(nums2[j],1);
                if(nums2[j]==0)count2++;
            }


            if(sum1<sum2){
                if(count1>=1) return sum2;
                else return -1;
                         }

            if(sum1>sum2){
                if(count2>=1) return sum1;
                else return -1;
                         }


       return sum1;
    }
};