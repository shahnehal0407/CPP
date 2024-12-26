class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>umap;
        int start=0;
        int maxlength=0;
        for(int end=0;end<s.size();end++){
            if((umap.find(s[end])!=umap.end())&& umap[s[end]]>=start)
                start= umap[s[end]]+1;
       
              umap[s[end]]=end;
        maxlength=max(maxlength,end-start+1);
        }
   
         return maxlength;
    }
};