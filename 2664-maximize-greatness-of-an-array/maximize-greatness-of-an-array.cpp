class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
         vector<int>copy(nums.begin(),nums.end());
         sort(copy.begin(),copy.end());


            int i=0;
            int j=0;
            int count=0;
            while (i < nums.size() && j < nums.size()){
                if(copy[i]<copy[j]){count++;j++;i++;}
                else j++;
            }
            return count;
    }
};