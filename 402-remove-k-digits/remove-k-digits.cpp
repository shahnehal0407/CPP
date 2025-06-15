class Solution {
public:
    string removeKdigits(string nums, int k) {

        stack<char>a;

        for(int i=0;i<nums.size();i++){
            while(k>0 && !a.empty() && a.top()>nums[i]){
                a.pop();
                k--;
            }
            a.push(nums[i]);
        }
        
            while(k>0 && !a.empty()){
                a.pop();
                k--;
            }
        string res="";
        while(!a.empty()){
            res+=a.top();
            a.pop();

        }
      reverse(res.begin(),res.end());
      int m=0;
      for(int i=0;i<res.size();i++){
        if(res[i]=='0') m++;
        else break;
      }


        res = res.substr(m);
     return res.empty() ? "0" :res;
    }
};