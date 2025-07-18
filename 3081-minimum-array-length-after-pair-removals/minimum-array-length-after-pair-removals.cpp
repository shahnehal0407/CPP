class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int m=nums.size();
        
        int i=0;
        int j=0;
        if(m%2==1){
            j=(m/2)+1;
        }else  j=m/2;
        int count=0;
while(i<m/2 && j<m){
    if(nums[i]<nums[j]){
        count++;
        j++;
        i++;

    }
    else if(nums[i]==nums[j]){
        j++;

    }
}

 return m-2*count;

        
    }
};