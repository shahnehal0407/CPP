class Solution {
public:
    bool linearsearch(vector<int>&a, int num){
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]==num) return true;
        }
        return false;
    }



    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int longest =1;
        unordered_set<int> st;
    
    for (int i = 0; i < n; i++) {
        st.insert(nums[i]);
        }

  for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

    }
};