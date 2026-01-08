class Solution {
public:


    int reversenum(int x){

        int rev=0;
        while(x>0){       
        rev= rev*10+(x%10);
        x=x/10;}

        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
            unordered_set<int>temp;
            for(int i=0;i<nums.size();i++){
                temp.insert(nums[i]);
                temp.insert(reversenum(nums[i]));
            }
             return temp.size();
        }
    
       
};