class Solution {
public:
    int atmost(vector<int>& s, int k) {
        int maxi=0;
        int l=0;
        int m=0;
        unordered_map<int ,int>store;
        for(int i=0;i<s.size();i++){
            if(store[s[i]]==0)m++;
            store[s[i]]++;

            while(m>k){
                store[s[l]]--;
                if(store[s[l]]==0)m--;
                l++;
                
            }
            maxi += i - l + 1;

        }
        return maxi;
    }

    int subarraysWithKDistinct(vector<int>& s, int k) {
       return  atmost(s,k) - atmost(s,k-1);

    }
};