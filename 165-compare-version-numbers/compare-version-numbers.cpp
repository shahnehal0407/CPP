class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1);
        string token;
        vector<int>v1;
         vector<int>v2;

        while(getline(s1,token,'.')){
            v1.push_back(stoi(token));
        }
            stringstream s2(version2);
        
        while(getline(s2,token,'.')){
            v2.push_back(stoi(token));
        }
        int n = max(v1.size(),v2.size());
        if(v1.size()<v2.size()) v1.resize(v2.size(),0);
        else v2.resize(v1.size(),0);
        int i=0;
        while(i<n){
            if(v1[i]<v2[i]){return -1;break;}
            else if(v1[i]>v2[i]){return 1;break;}
            i++;
        }
        return 0;
    }
};