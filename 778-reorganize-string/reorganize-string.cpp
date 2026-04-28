class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26,0);
        for ( char c : s)freq[c-'a']++;
        int n=s.size();

        int maxfreq=0;
        int maxchar=0;
        for (int i=0;i<26;i++){
            if(freq[i]>maxfreq){ maxfreq=freq[i];
            maxchar=i;
            }
        }

        if(maxfreq>(n+1)/2)return "";

        string res(n,' ');
        int idx=0;

        while(freq[maxchar]>0){
            res[idx]=maxchar+'a';
            idx+=2;
            freq[maxchar]--;
        }

        for(int i=0;i<26;i++){
            while(freq[i]>0){
            if(idx>=n)idx=1;
            res[idx]=i+'a';
            freq[i]--;
            idx+=2;
            }
            
            

        }
        return res;

    }
};
